package com.ljx.susheguanli.activity;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.text.TextUtils;
import android.view.View;
import android.widget.EditText;
import android.widget.ListView;
import android.widget.Toast;

import com.ljx.susheguanli.R;
import com.ljx.susheguanli.adapter.Adapter;
import com.ljx.susheguanli.database.DbDormitory;
import com.ljx.susheguanli.entity.DormitoryBean;

import java.util.ArrayList;
import java.util.List;

public class QueryDormitoryActivity extends AppCompatActivity implements View.OnClickListener {
    ListView QueryLv;//列表
    EditText EtNumber, EtName;//输入框宿舍号和姓名
    List<DormitoryBean> mData;//数据源
    Adapter adapter;//适配器对象
    DbDormitory dbDormitory;//数据库

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_query_dormitory);//绑定所有事件
        QueryLv = findViewById(R.id.query_lv);
        EtName = findViewById(R.id.et_name);
        EtNumber = findViewById(R.id.et_number);
        mData = new ArrayList<>();
        adapter = new Adapter(this, mData);
        QueryLv.setAdapter(adapter);
        dbDormitory =new DbDormitory(this);

    }
/**
 * 按钮点击事件
 * */
    @Override
    public void onClick(View v) {
        switch (v.getId()) {
            case R.id.iv_back:
                Intent intent = new Intent(QueryDormitoryActivity.this, MainActivity.class);
                //实现页面跳转
                startActivity(intent);
                finish();
                break;
            case R.id.iv_query:
                String number = EtNumber.getText().toString().trim();
                String name = EtName.getText().toString().trim();
                if (TextUtils.isEmpty(number)) {
                    Toast.makeText(this, "请输入宿舍号！", Toast.LENGTH_SHORT).show();
                } else if (TextUtils.isEmpty(name)) {
                    Toast.makeText(this, "请输入姓名！", Toast.LENGTH_SHORT).show();
                } else {
                    //开始搜索
                    List<DormitoryBean> list = DbDormitory.getDormitoryListByNumberAndName(number,name);
                    mData.clear();//将原来搜索的消息清除
                    mData.addAll(list);//显示在列表上
                    adapter.notifyDataSetChanged();//实时更新
                    break;

                }
        }
    }
}