package com.ljx.susheguanli.activity;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.ImageButton;
import android.widget.ListView;

import com.ljx.susheguanli.R;
import com.ljx.susheguanli.adapter.Adapter;
import com.ljx.susheguanli.database.DbDormitory;
import com.ljx.susheguanli.entity.DormitoryBean;

import java.util.ArrayList;
import java.util.List;

public class SearchDormitoryActivity extends AppCompatActivity implements View.OnClickListener {
    ImageButton BtnBack;//退出按钮
    ListView listView;//列表
    List<DormitoryBean> mData;//数据源
    Adapter adapter;//适配器
    DbDormitory dbDormitory;//数据库

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_search_dormitory);//绑定事件
        BtnBack = findViewById(R.id.btn_back);
        BtnBack.setOnClickListener(this);
        listView = findViewById(R.id.listView);
        dbDormitory = new DbDormitory(this);
        mData = new ArrayList<>();
        System.out.println("长度为:" + mData.size());
        //设置适配器：加载每一行数据到列表当中
        adapter = new Adapter(this, mData);
        listView.setAdapter(adapter);
        loadData();//显示学生信息列表函数
    }

    /**
     * 显示学生信息列表
     */
    private void loadData() {
        List<DormitoryBean> list = DbDormitory.search();
        mData.clear();
        mData.addAll(list);
        adapter.notifyDataSetChanged();//实时更新
    }

    @Override
    public void onClick(View v) {
        switch (v.getId()) {
            case R.id.btn_back:
                Intent intent = new Intent(SearchDormitoryActivity.this, MainActivity.class);
                startActivity(intent);
                finish();
                break;
        }
    }
}