package com.example.myapplication;


import android.annotation.SuppressLint;
import android.content.Intent;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteException;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import androidx.appcompat.app.AlertDialog;
import androidx.appcompat.app.AppCompatActivity;

public class MainaActivity extends AppCompatActivity {
    private Button btn_quit;
    @SuppressLint("WrongViewCast")
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        btn_quit = (Button) findViewById(R.id.btn_quit);
    }

    public void GoLogin(View view) {
        // 获取用户填写的信息
        String name = ((EditText) findViewById(R.id.edit_user)).getText().toString();
        String password = ((EditText) findViewById(R.id.edit_pwd)).getText().toString();

        // 在数据库中查询用户信息
        SQLiteDatabase db;
        try {
            db = SQLiteDatabase.openDatabase(getFilesDir().getAbsolutePath() + "/user.db", null, SQLiteDatabase.OPEN_READONLY);
        } catch (SQLiteException e) {
            Toast.makeText(this, "用户名或密码不正确", Toast.LENGTH_SHORT).show();
            return;
        }
        Cursor cursor = db.rawQuery("SELECT * FROM user WHERE name=? AND password=?", new String[]{name, password});
        if (cursor.moveToFirst()) {
            // 用户名和密码匹配，跳转到MainActivity2页面
            Intent intent = new Intent(this, MainActivity2.class);
            startActivity(intent);
        } else {
            // 用户名或密码不对，提示用户
            Toast.makeText(this, "用户名或密码不正确", Toast.LENGTH_SHORT).show();
        }
        cursor.close();
        db.close();
    }
    public void GoEnroll(View view) {
        Intent intent = new Intent(this, MainActivity3.class);
        // 进行跳转
        startActivity(intent);
    }

    public void GoInquire(View view) {
        Intent intent = new Intent(this, MainActivity4.class);
        // 进行跳转
        startActivity(intent);
    }


    @SuppressLint("NonConstantResourceId")
    public void GoQuit(View v) {
        if (v.getId() == R.id.btn_quit) {
            AlertDialog.Builder builder = new AlertDialog.Builder(this);
            builder.setTitle("确认退出");
            builder.setMessage("是否确定退出软件？");
            builder.setPositiveButton("是", (dialog, which) -> {
                finish();
                System.exit(0);
            });
            builder.setNegativeButton("否", null);
            builder.show();
        }

    }

}
