package com.example.memorizewords;

import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.EditText;
import android.widget.RadioButton;
import android.widget.Spinner;
import android.widget.Toast;
import android.widget.ToggleButton;

import androidx.appcompat.app.AppCompatActivity;

public class MainActivity3 extends AppCompatActivity implements View.OnClickListener {
    private EditText editText1, editText2, editText3;
    private RadioButton radioButton, radioButton2;
    private ToggleButton toggleButton;
    private CheckBox checkBox, checkBox2, checkBox3;
    private Spinner spinner;
    private Button button;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main3);

        // 获取控件
        editText1 = findViewById(R.id.editText1);
        editText2 = findViewById(R.id.editText2);
        editText3 = findViewById(R.id.editText3);
        radioButton = findViewById(R.id.radioButton);
        radioButton2 = findViewById(R.id.radioButton2);
        toggleButton = findViewById(R.id.toggleButton);
        checkBox = findViewById(R.id.checkBox);
        checkBox2 = findViewById(R.id.checkBox2);
        checkBox3 = findViewById(R.id.checkBox3);
        spinner = findViewById(R.id.spinner);
        button = findViewById(R.id.button7);

        // 设置点击事件
        button.setOnClickListener(this);
    }
    public void btn_finish(View v) {
        if (v.getId()==R.id.btn_finish ){
            finish();
        }
    }
    @Override
    public void onClick(View v) {
        if (v.getId() == R.id.button7) {// 获取用户填写的信息
            String name = editText1.getText().toString();
            String password = editText2.getText().toString();
            String realName = editText3.getText().toString();
            String gender = radioButton.isChecked() ? "男" : "女";
            String marriage = toggleButton.isChecked() ? "已婚" : "未婚";
            String hobby = "";
            if (checkBox.isChecked()) {
                hobby += checkBox.getText().toString() + " ";
            }
            if (checkBox2.isChecked()) {
                hobby += checkBox2.getText().toString() + " ";
            }
            if (checkBox3.isChecked()) {
                hobby += checkBox3.getText().toString() + " ";
            }
            String major = spinner.getSelectedItem().toString();

            // 判断用户填写的信息是否完整
            if (name.isEmpty() || password.isEmpty() || realName.isEmpty() || gender.isEmpty() || marriage.isEmpty() || hobby.isEmpty() || major.isEmpty()) {
                Toast.makeText(this, "请填写完整信息", Toast.LENGTH_SHORT).show();
                return;
            }

            // 判断密码位数是否正确
            if (password.length() != 6 || !password.matches("\\d{6}")) {
                Toast.makeText(this, "密码格式仅支持6位数字，请重新输入", Toast.LENGTH_SHORT).show();
                return;
            }

            // 判断用户是否已经存在
            SQLiteDatabase db = SQLiteDatabase.openOrCreateDatabase(getFilesDir().getAbsolutePath() + "/user.db", null);
            if (db != null && db.isOpen()) {
                Log.d("note", "数据库打开成功");
                db.execSQL("CREATE TABLE IF NOT EXISTS user (_id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT, password TEXT, realName TEXT, gender TEXT, marriage TEXT, hobby TEXT, major TEXT)");
                Cursor cursor = db.rawQuery("SELECT * FROM user WHERE name=?", new String[]{name});
                if (cursor.moveToFirst()) {
                    Toast.makeText(this, "该用户已经存在", Toast.LENGTH_SHORT).show();
                } else {
                    db.execSQL("INSERT INTO user (name, password, realName, gender, marriage, hobby, major) VALUES (?, ?, ?, ?, ?, ?, ?)", new Object[]{name, password, realName, gender, marriage, hobby, major});
                    Toast.makeText(this, "注册成功", Toast.LENGTH_SHORT).show();
                }
                cursor.close();
                db.close();
            } else {
                Log.e("note", "数据库打开失败");
            }
        }
    }
}
