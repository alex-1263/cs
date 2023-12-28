package com.ljx.susheguanli.activity;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.text.TextUtils;
import android.view.View;
import android.widget.AdapterView;
import android.widget.EditText;
import android.widget.ListView;
import android.widget.Toast;

import com.ljx.susheguanli.R;
import com.ljx.susheguanli.adapter.Adapter_update;
import com.ljx.susheguanli.database.DbDormitory;
import com.ljx.susheguanli.entity.DormitoryBean;

import java.util.ArrayList;
import java.util.List;

public class ModDormitoryActivity extends AppCompatActivity implements View.OnClickListener {
    ListView UpdateLv;//列表
    EditText EtNumber;//宿舍号
    List<DormitoryBean> mData;//数据源
    Adapter_update adapter;//适配器对象
    DbDormitory dbDormitory;//数据库

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_mod_dormitory);//绑定事件
        UpdateLv = findViewById(R.id.update_lv);
        EtNumber = findViewById(R.id.et_update);
        mData = new ArrayList<>();
        adapter = new Adapter_update(this, mData);
        UpdateLv.setAdapter(adapter);//适配器列表显示
        dbDormitory = new DbDormitory(this);

    }
/**
 * 按钮点击事件
 * */
    @Override
    public void onClick(View v) {
        switch (v.getId()) {
            case R.id.iv_back:
                Intent intent = new Intent(ModDormitoryActivity.this, MainActivity.class);
                startActivity(intent);
                finish();
                break;
            case R.id.update_iv:
                String number = EtNumber.getText().toString().trim();
                DormitoryBean dormitoryBeans = dbDormitory.QueryFromDormitoryByNumber(number);//查询学号是否存在
                if (TextUtils.isEmpty(number)) {
                    Toast.makeText(this, "请输入宿舍号！", Toast.LENGTH_SHORT).show();
                } else if (dormitoryBeans == null) {
                    Toast.makeText(this, "该宿舍号不存在！", Toast.LENGTH_SHORT).show();
                } else {
                    //开始搜索
                    List<DormitoryBean> list = DbDormitory.getDormitoryListByNumber(number);//查询该学号的所有信息
                    mData.clear();//将原来搜索的消息清除
                    mData.addAll(list);
                    adapter.notifyDataSetChanged();//实时更新
                    initData();//修改信息函数
                    break;

                }
        }
    }
/**
 * 修改信息点击事件，点击就会进入到修改页面进行修改
 * */
    private void initData() {
        dbDormitory = new DbDormitory(this); //创建数据库
        UpdateLv.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> parent, View view, int position, long id){
                DormitoryBean dormitoryBean = mData.get(position);
                Intent intent = new Intent(ModDormitoryActivity.this, AddDormitoryActivity.class);
                intent.putExtra("number", dormitoryBean.getNumber());
                intent.putExtra("name", dormitoryBean.getName());
                intent.putExtra("much", dormitoryBean.getMuch());
                intent.putExtra("sex", dormitoryBean.getSex());
                intent.putExtra("time", dormitoryBean.getTime());
                intent.putExtra("address", dormitoryBean.getAddress());
                intent.putExtra("des", dormitoryBean.getDes());
                ModDormitoryActivity.this.startActivityForResult(intent, 1);
            }
        });
    }
}