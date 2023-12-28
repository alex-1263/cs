package edu.cn.bookadminister.app;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

import edu.cn.bookadminister.activity.AddbooksActivity;
import edu.cn.bookadminister.activity.DeleteBooksActivity;
import edu.cn.bookadminister.activity.QueryBooksActivity;
import edu.cn.bookadminister.R;
import edu.cn.bookadminister.activity.UpdateBooksActivity;

public class MainActivity extends AppCompatActivity implements View.OnClickListener {

    private Button btnAdd;
    private Button btnUpdate;
    private Button btnDelete;
    private Button btnQuery;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        btnAdd = findViewById(R.id.btn_add);
        btnDelete = findViewById(R.id.btn_delete);
        btnUpdate = findViewById(R.id.btn_update);
        btnQuery = findViewById(R.id.btn_query);
        btnAdd.setOnClickListener(this);
        btnDelete.setOnClickListener(this);
        btnUpdate.setOnClickListener(this);
        btnQuery.setOnClickListener(this);

    }

    @Override
    public void onClick(View v) {
        switch (v.getId()) {
            case R.id.btn_add:
                Intent intent = new Intent(MainActivity.this, AddbooksActivity.class);
                startActivityForResult(intent, 0);
                break;
            case R.id.btn_update:
                Intent intent1 = new Intent(MainActivity.this, UpdateBooksActivity.class);
                startActivityForResult(intent1, 1);
                break;
            case R.id.btn_delete:
                Intent intent2 = new Intent(MainActivity.this, DeleteBooksActivity.class);
                startActivityForResult(intent2, 2);
                break;
            case R.id.btn_query:
                Intent intent3 = new Intent(MainActivity.this, QueryBooksActivity.class);
                startActivityForResult(intent3, 3);
                break;
            default:
                break;
        }

    }
}

