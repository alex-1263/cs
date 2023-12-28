package com.ljx.susheguanli.activity;

import androidx.appcompat.app.AppCompatActivity;

import android.app.AlertDialog;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;

import com.ljx.susheguanli.R;

public class MainActivity extends AppCompatActivity implements View.OnClickListener{
    private Button btnAdd,btnSearch,btnMod,btnQuery,btnDelete,btnBack;
    //按钮：录入、浏览、修改、查询、删除、退出

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);//事件绑定
        btnAdd=findViewById(R.id.add_dormitory);
        btnSearch=findViewById(R.id.search_dormitory);
        btnMod=findViewById(R.id.mod_dormitory);
        btnDelete=findViewById(R.id.delete_dormitory);
        btnQuery=findViewById(R.id.query_dormitory);
        btnBack=findViewById(R.id.btn_back);
        btnBack.setOnClickListener(this);
        btnQuery.setOnClickListener(this);
        btnDelete.setOnClickListener(this);
        btnMod.setOnClickListener(this);
        btnAdd.setOnClickListener(this);
        btnSearch.setOnClickListener(this);

    }
/**
 * 按钮点击事件
 * */
    @Override
    public void onClick(View v) {
        switch (v.getId()){
            case R.id.add_dormitory:
                Intent intent1=new Intent(MainActivity.this, AddDormitoryActivity.class);
                startActivity(intent1);
                break;
            case R.id.search_dormitory:
                Intent intent2=new Intent(MainActivity.this, SearchDormitoryActivity.class);
                startActivity(intent2);
                break;
            case R.id.mod_dormitory:
                Intent intent3=new Intent(MainActivity.this, ModDormitoryActivity.class);
                startActivity(intent3);
                break;
            case R.id.query_dormitory:
                Intent intent4=new Intent(MainActivity.this, QueryDormitoryActivity.class);
                startActivity(intent4);
                break;
            case R.id.delete_dormitory:
                Intent intent5=new Intent(MainActivity.this, DeleteDormitoryActivity.class);
                startActivity(intent5);
                break;
            case R.id.btn_back:
                DigLogShow();
                break;
        }
    }
/**
 * 退出提示
 * */
    private void DigLogShow() {
        final AlertDialog.Builder builder = new AlertDialog.Builder(this);
        builder.setTitle("退出提示")
                .setMessage("是否退出？")
                .setPositiveButton("否", new DialogInterface.OnClickListener() {
                    @Override
                    public void onClick(DialogInterface dialog, int which) {
                    }
                })
                .setNegativeButton("是", new DialogInterface.OnClickListener() {
                    @Override
                    public void onClick(DialogInterface dialog, int which) {
                        Intent intent6=new Intent(MainActivity.this,LoginActivity.class);
                        SharedPreferences sharedPreferences = getSharedPreferences("zidong", Context.MODE_PRIVATE);
                        sharedPreferences.edit().clear().apply();
                        Toast.makeText(MainActivity.this,"退出成功！",Toast.LENGTH_LONG).show();
                        startActivity(intent6);
                    }
                });
        builder.create().show();
    }
}