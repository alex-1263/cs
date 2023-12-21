package com.example.memorizewords;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;

import android.content.ContentValues;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteException;
import android.os.Bundle;
import android.view.View;
import android.widget.EditText;
import android.widget.Toast;

public class MainActivity4 extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main4);
    }
    public void onClick(View view) {
        switch (view.getId()) {
            case R.id.btn_update:
                EditText etUser = findViewById(R.id.et_user);
                EditText etPwd = findViewById(R.id.et_pwd);
                EditText etPwd2 = findViewById(R.id.et_pwd2);
                String user = etUser.getText().toString();
                String pwd = etPwd.getText().toString();
                String pwd2 = etPwd2.getText().toString();
                if (user.isEmpty() || pwd.isEmpty() || pwd2.isEmpty()) {
                    Toast.makeText(this, "请输入完整信息", Toast.LENGTH_SHORT).show();
                } else if (!pwd.equals(pwd2)) {
                    Toast.makeText(this, "两次密码不一致，请再次输入密码", Toast.LENGTH_SHORT).show();
                } else {
                    SQLiteDatabase db = null;
                    Cursor cursor = null;
                    try {
                        db = SQLiteDatabase.openDatabase(getFilesDir().getAbsolutePath() + "/user.db", null, SQLiteDatabase.OPEN_READWRITE);
                        cursor = db.rawQuery("SELECT * FROM user WHERE name=?", new String[]{user});
                        if (cursor.moveToFirst()) {
                            ContentValues values = new ContentValues();
                            values.put("password", pwd);
                            db.update("user", values, "name=?", new String[]{user});
                            Toast.makeText(this, "修改成功", Toast.LENGTH_SHORT).show();
                        } else {
                            Toast.makeText(this, "该用户名不存在", Toast.LENGTH_SHORT).show();
                        }
                    } catch (SQLiteException e) {
                        Toast.makeText(this, "该用户名不存在", Toast.LENGTH_SHORT).show();
                    } finally {
                        if (cursor != null) {
                            cursor.close();
                        }
                        if (db != null) {
                            db.close();
                        }
                    }
                }
                break;
            default:
                break;
        }
    }
    public void btn_finish(@NonNull View v) {
        if (v.getId()==R.id.btn_finish ){
            finish();
        }
    }
}
