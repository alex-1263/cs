package com.example.memorizewords;

import android.annotation.SuppressLint;
import android.content.ContentValues;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteException;
import android.os.Bundle;
import android.text.method.ScrollingMovementMethod;
import android.view.Gravity;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.EditText;
import android.widget.RatingBar;
import android.widget.TableLayout;
import android.widget.TableRow;
import android.widget.TextView;
import android.widget.Toast;

import androidx.annotation.Nullable;
import androidx.appcompat.app.AlertDialog;
import androidx.appcompat.app.AppCompatActivity;

public class MainActivity2 extends AppCompatActivity implements OnClickListener {



    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main2);

    }


    public void onClick(View v) {
        if (v.getId() == R.id.bt_save) {
            EditText etUsername = findViewById(R.id.et_username);
            EditText etPassword = findViewById(R.id.et_password);
            String username = etUsername.getText().toString();
            String password = etPassword.getText().toString();
            if (username.equals("") || password.equals("")) {
                // 判断单词和翻译是否为空
                Toast.makeText(this, "请填写完整单词信息", Toast.LENGTH_SHORT).show();
            } else {
                SQLiteDatabase db = SQLiteDatabase.openOrCreateDatabase(getFilesDir().getAbsolutePath() + "/word.db", null);
                db.execSQL("CREATE TABLE IF NOT EXISTS words(_id INTEGER PRIMARY KEY AUTOINCREMENT, word TEXT, translation TEXT)");
                Cursor cursor = db.rawQuery("SELECT * FROM words WHERE word=?", new String[]{username});
                if (cursor.getCount() > 0) {
                    // 判断单词是否已经存在
                    Toast.makeText(this, "此单词已经添加", Toast.LENGTH_SHORT).show();
                } else {
                    ContentValues values = new ContentValues();
                    values.put("word", username);
                    values.put("translation", password);
                    db.insert("words", null, values);
                    Toast.makeText(this, "添加成功", Toast.LENGTH_SHORT).show();
                    // 清空单词和翻译文本
                    etUsername.setText("");
                    etPassword.setText("");
                }
                cursor.close();
                db.close();
            }
        } else if (v.getId() == R.id.bt_query) {
            TableLayout tlData = findViewById(R.id.tl_data);
            // 清空表格数据
            tlData.removeAllViews();
            SQLiteDatabase db = null;
            Cursor cursor = null;
            try {
                db = SQLiteDatabase.openDatabase(getFilesDir().getAbsolutePath() + "/word.db", null, SQLiteDatabase.OPEN_READWRITE);
                cursor = db.rawQuery("SELECT * FROM words ORDER BY _id ASC", null);
                if (cursor.getCount() == 0) {
                    Toast.makeText(this, "数据表中无单词，请先添加单词", Toast.LENGTH_SHORT).show();
                    return;
                }
                int index = 1;
                while (cursor.moveToNext()) {
                    @SuppressLint("Range") String word = cursor.getString(cursor.getColumnIndex("word"));
                    @SuppressLint("Range") String translation = cursor.getString(cursor.getColumnIndex("translation"));
                    TableRow trData = new TableRow(this);
                    TextView tvIndexData = new TextView(this);
                    tvIndexData.setText(String.valueOf(index));
                    tvIndexData.setTextSize(20);
                    tvIndexData.setPadding(100, 5, 100, 0);
                    trData.addView(tvIndexData);
                    TextView tvWordData = new TextView(this);
                    tvWordData.setText(word);
                    tvWordData.setTextSize(20);
                    tvWordData.setWidth(400);
                    trData.addView(tvWordData);
                    TextView tvTranslationData = new TextView(this);
                    tvTranslationData.setText(translation);                tvTranslationData.setTextSize(20);
                    tvTranslationData.setPadding(160, 5, 0, 0);
                    trData.addView(tvTranslationData);
                    tlData.addView(trData);
                    // 将表格数据居中显示
                    tvIndexData.setGravity(Gravity.CENTER);
                    tvWordData.setGravity(Gravity.CENTER);
                    tvTranslationData.setGravity(Gravity.CENTER);
                    index++;
                }
            } catch (SQLiteException e) {
                Toast.makeText(this, "数据表中无单词，请先添加单词", Toast.LENGTH_SHORT).show();
            } finally {
                if (cursor != null) {
                    cursor.close();
                }
                if (db != null) {
                    db.close();
                }
            }
            tlData.requestLayout();
        } else if (v.getId() == R.id.bt_delete) {
            EditText etUsername = findViewById(R.id.et_username);
            EditText etPassword = findViewById(R.id.et_password);
            String username = etUsername.getText().toString();
            String password = etPassword.getText().toString();
            if (username.equals("") || password.equals("")) {
                // 判断单词和翻译是否为空
                Toast.makeText(this, "请填写完整单词信息", Toast.LENGTH_SHORT).show();
            } else {
                SQLiteDatabase db = SQLiteDatabase.openOrCreateDatabase(getFilesDir().getAbsolutePath() + "/word.db", null);
                Cursor cursor = db.rawQuery("SELECT * FROM words WHERE word=? AND translation=?", new String[]{username, password});
                if (cursor.getCount() > 0) {
                    db.execSQL("DELETE FROM words WHERE word=? AND translation=?", new String[]{username, password});
                    Toast.makeText(this, "删除成功", Toast.LENGTH_SHORT).show();
                    // 清空单词和翻译文本
                    etUsername.setText("");
                    etPassword.setText("");
                } else {
                    Toast.makeText(this, "单词或翻译错误，请重新输入", Toast.LENGTH_SHORT).show();
                }
                cursor.close();
                db.close();
            }
        } else if (v.getId() == R.id.bt_update) {
            EditText etUsername = findViewById(R.id.et_username);
            EditText etPassword = findViewById(R.id.et_password);
            String username = etUsername.getText().toString();
            String password = etPassword.getText().toString();
            if (username.equals("") || password.equals("")) {
                // 判断单词和翻译是否为空
                Toast.makeText(this, "请填写完整单词信息", Toast.LENGTH_SHORT).show();
            } else {
                SQLiteDatabase db = SQLiteDatabase.openOrCreateDatabase(getFilesDir().getAbsolutePath() + "/word.db", null);
                Cursor cursor = db.rawQuery("SELECT * FROM words WHERE word=?", new String[]{username});
                if (cursor.getCount() > 0) {
                    ContentValues values = new ContentValues();
                    values.put("translation", password);
                    db.update("words", values, "word=?", new String[]{username});
                    Toast.makeText(this, "修改成功", Toast.LENGTH_SHORT).show();
                    // 清空单词和翻译文本
                    etUsername.setText("");
                    etPassword.setText("");
                } else {
                    Toast.makeText(this, "单词或翻译错误，请重新输入", Toast.LENGTH_SHORT).show();
                }
                cursor.close();
                db.close();
            }
        }
    }
    public void submit(View view) {
        RatingBar ratingBar = findViewById(R.id.ratingBar);
        float rating = ratingBar.getRating();
        Toast.makeText(this, "您提交了 " + rating + " 颗星的评价", Toast.LENGTH_SHORT).show();
        ratingBar.setRating(0);
    }


    public void btn_finish(View v) {
        if (v.getId()==R.id.btn_finish ){
            finish();
        }
    }
}
