package com.ljx.susheguanli.activity;

import androidx.appcompat.app.AppCompatActivity;

import android.app.AlertDialog;
import android.content.DialogInterface;
import android.content.Intent;
import android.os.Bundle;
import android.text.TextUtils;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ImageButton;
import android.widget.TextView;
import android.widget.Toast;

import com.ljx.susheguanli.R;
import com.ljx.susheguanli.database.DbDormitory;
import com.ljx.susheguanli.entity.DormitoryBean;

import java.util.ArrayList;
import java.util.List;

public class AddDormitoryActivity extends AppCompatActivity implements View.OnClickListener {
    private ImageButton BtnBack;//返回按钮
    private TextView tv_title;//头标题
    private EditText EtName, EtNumber, EtMuch, EtSex, EtTime, EtAddress, EtDes;
    //姓名、宿舍号、人数、类别、入住时间、楼层、备注
    private Button BtnSave;//保存按钮
    DbDormitory dbDormitory;//数据库
    List<DormitoryBean> mData;//数据源
    String number;//宿舍号

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_add_dormitory);
        tv_title=findViewById(R.id.tv_title);//绑定控件
        BtnBack = findViewById(R.id.btn_back);
        BtnSave = findViewById(R.id.btn_save);
        BtnBack.setOnClickListener(this);
        BtnSave.setOnClickListener(this);
        EtNumber = findViewById(R.id.add_et_number);
        EtName = findViewById(R.id.add_et_name);
        EtMuch = findViewById(R.id.add_et_much);
        EtSex = findViewById(R.id.add_et_sex);
        EtTime = findViewById(R.id.add_et_birthday);
        EtAddress = findViewById(R.id.add_et_address);
        EtDes = findViewById(R.id.add_et_des);
        dbDormitory = new DbDormitory(this);
        mData = new ArrayList<>();
        initData();
    }
/**
 * 保存修改的信息
 * */
    private void initData() {
        Intent intent = getIntent();
        if (intent != null) {
            number = intent.getStringExtra("number");
            if (number != null) {
                tv_title.setText("修改宿舍信息");
                BtnSave.setText("修  改");
                EtNumber.setText(intent.getStringExtra("number"));
                EtName.setText(intent.getStringExtra("name"));
                EtMuch.setText(intent.getStringExtra("much"));
                EtSex.setText(intent.getStringExtra("sex"));
                EtTime.setText(intent.getStringExtra("time"));
                EtAddress.setText(intent.getStringExtra("address"));
                EtDes.setText(intent.getStringExtra("des"));
            }
        }
    }

    @Override
    public void onClick(View v) {
        switch (v.getId()) {
            case R.id.btn_back:
                Intent intent1 = new Intent(AddDormitoryActivity.this, MainActivity.class);
                startActivity(intent1);
                break;
            case R.id.btn_save:
                //输入
                String number = EtNumber.getText().toString().trim();
                String name = EtName.getText().toString().trim();
                String year = EtMuch.getText().toString().trim();
                String sex = EtSex.getText().toString().trim();
                String birth = EtTime.getText().toString().trim();
                String address = EtAddress.getText().toString().trim();
                String phone = EtDes.getText().toString().trim();
                DormitoryBean dormitoryBeans = dbDormitory.QueryFromDormitoryByNumber(number);
                if (number != null) {//修改操作
                    if (name.length() > 0) {
                        if (dbDormitory.updateDormitory(number, name, year,sex,birth,address,phone)) {
                            Toast.makeText(AddDormitoryActivity.this,"修改成功",Toast.LENGTH_LONG).show();
                            setResult(2);
                            showDeleteDialog2();
                        }
                    } else {
                        Toast.makeText(AddDormitoryActivity.this,"修改的内容不能为空！",Toast.LENGTH_LONG).show();
                    }

                }
                if (TextUtils.isEmpty(name)) {
                    Toast.makeText(AddDormitoryActivity.this, "录入失败！请输入入住人", Toast.LENGTH_SHORT).show();
                } else if (TextUtils.isEmpty(number)) {
                    Toast.makeText(AddDormitoryActivity.this, "录入失败！请输入宿舍号", Toast.LENGTH_SHORT).show();
                } else if (TextUtils.isEmpty(year)) {
                    Toast.makeText(AddDormitoryActivity.this, "录入失败！请输入人数", Toast.LENGTH_SHORT).show();
                } else if (TextUtils.isEmpty(sex)) {
                    Toast.makeText(AddDormitoryActivity.this, "录入失败！请输入类别", Toast.LENGTH_SHORT).show();
                } else if (TextUtils.isEmpty(birth)) {
                    Toast.makeText(AddDormitoryActivity.this, "录入失败！请输入入住时间", Toast.LENGTH_SHORT).show();
                } else if (TextUtils.isEmpty(address)) {
                    Toast.makeText(AddDormitoryActivity.this, "录入失败！请输入楼层", Toast.LENGTH_SHORT).show();
                } else if (TextUtils.isEmpty(phone)) {
                    Toast.makeText(AddDormitoryActivity.this, "录入失败！请输入备注", Toast.LENGTH_SHORT).show();
                }else if (dormitoryBeans != null){
                    Toast.makeText(AddDormitoryActivity.this, "宿舍号重复", Toast.LENGTH_SHORT).show();
                }
                else {
                    System.out.println("是否为空: "+ dbDormitory);
                    dbDormitory.insertDormitory(number, name, year, sex, birth, address, phone);
                    showDeleteDialog();

                    }
                }
    }
/**
 * 修改提示框
 * */
    private void showDeleteDialog2() {
        final AlertDialog.Builder builder = new AlertDialog.Builder(this);
        builder.setTitle("修改成功提示")
                .setMessage("已成功修改！")
                .setPositiveButton("ok", new DialogInterface.OnClickListener() {
                    @Override
                    public void onClick(DialogInterface dialog, int which) {
                        Intent intent=new Intent(AddDormitoryActivity.this,MainActivity.class);
                        startActivity(intent);
                    }
                });
        builder.create().show();
    }
    /**
     * 保存提示框
     * */
    private void showDeleteDialog() {
        final AlertDialog.Builder builder = new AlertDialog.Builder(this);
        builder.setTitle("录入成功提示")
                .setMessage("已成功录入！\n是否继续？")
                .setPositiveButton("否", new DialogInterface.OnClickListener() {
                    @Override
                    public void onClick(DialogInterface dialog, int which) {
                        Intent intent=new Intent(AddDormitoryActivity.this,MainActivity.class);
                        startActivity(intent);
                    }
                })
                .setNegativeButton("是", new DialogInterface.OnClickListener() {
                    @Override
                    public void onClick(DialogInterface dialog, int which) {
                        //将输入框清空
                        EtNumber.setText("");
                        EtName.setText("");
                        EtMuch.setText("");
                        EtSex.setText("");
                        EtTime.setText("");
                        EtAddress.setText("");
                        EtDes.setText("");
                    }
                });
        builder.create().show();
    }
}