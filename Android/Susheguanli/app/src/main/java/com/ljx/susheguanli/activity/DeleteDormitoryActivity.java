package com.ljx.susheguanli.activity;

import androidx.appcompat.app.AppCompatActivity;

import android.app.AlertDialog;
import android.content.DialogInterface;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ListView;

import com.ljx.susheguanli.R;
import com.ljx.susheguanli.adapter.Adapter_del;
import com.ljx.susheguanli.database.DbDormitory;
import com.ljx.susheguanli.entity.DormitoryBean;

import java.util.ArrayList;
import java.util.List;

public class DeleteDormitoryActivity extends AppCompatActivity {
    ListView listView;//列表
    List<DormitoryBean> mData;//数据源
    Adapter_del adapter;//适配器
    DbDormitory dbDormitory;//数据库


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_delete_dormitory);//控件绑定
        listView = findViewById(R.id.del_lv);
        dbDormitory = new DbDormitory(this);
        mData = new ArrayList<>();
        System.out.println("长度为:" + mData.size());
        //设置适配器：加载每一行数据到列表当中
        adapter = new Adapter_del(this, mData);
        listView.setAdapter(adapter);
        loadData();
        setLVClickListener();
    }

    /**
     * listView长按事件
     */
    private void setLVClickListener() {
        listView.setOnItemLongClickListener(new AdapterView.OnItemLongClickListener() {
            @Override
            public boolean onItemLongClick(AdapterView<?> parent, View view, int position, long id) {
                DormitoryBean dormitoryBean = mData.get(position);
                deleteItem(dormitoryBean);
                return false;
            }
        });
    }
/**
 * 长按删除
 * */
    private void deleteItem(final DormitoryBean dormitoryBean) {
        final String delNumber = dormitoryBean.getNumber();
        AlertDialog.Builder builder = new AlertDialog.Builder(this);
        builder.setTitle("提示信息").setMessage("您确定要删除这条记录么？")
                .setNegativeButton("取消", null)
                .setPositiveButton("确定", new DialogInterface.OnClickListener() {
                    @Override
                    public void onClick(DialogInterface dialog, int which) {
                        DbDormitory.deleteItemFromDormitoryByNumber(delNumber);
                        mData.remove(dormitoryBean);    //实时刷新，从数据源删除
                        adapter.notifyDataSetChanged();
                    }
                });
        builder.create().show();
    }
/**
 * 显示宿舍信息列表
 * */
    private void loadData() {
        List<DormitoryBean> list = DbDormitory.search();
        mData.clear();
        mData.addAll(list);
        adapter.notifyDataSetChanged();
    }
    /**
     * 按钮点击事件
     * */
    public void onClick(View v) {
        switch (v.getId()) {
            case R.id.iv_back:
                Intent intent = new Intent(DeleteDormitoryActivity.this, MainActivity.class);
                startActivity(intent);
                finish();
                break;
        }

    }
}