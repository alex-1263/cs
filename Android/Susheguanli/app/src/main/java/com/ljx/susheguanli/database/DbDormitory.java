package com.ljx.susheguanli.database;

import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;

import androidx.annotation.Nullable;

import com.ljx.susheguanli.entity.DormitoryBean;

import java.util.ArrayList;
import java.util.List;

public class DbDormitory extends SQLiteOpenHelper {
    private static SQLiteDatabase db;
    public DbDormitory(@Nullable Context context) {
        super(context, "dormitory.db", null, 1);
        System.out.println("数据库创建成功");
        db = getReadableDatabase();
    }

    public static List<DormitoryBean> getDormitoryListByNumberAndName(String number , String name) {
        List<DormitoryBean> list = new ArrayList<>();
        String sql = "select * from dormitory where number like '%" + number + "%' and name like '%" + name + "%'";
        Cursor cursor = db.rawQuery(sql, null);
        while (cursor.moveToNext()) {
            int id = cursor.getInt(cursor.getColumnIndex("id"));
            String number1 = cursor.getString(cursor.getColumnIndex("number"));
            String name1 = cursor.getString(cursor.getColumnIndex("name"));
            String year = cursor.getString(cursor.getColumnIndex("much"));
            String sex = cursor.getString(cursor.getColumnIndex("sex"));
            String birth = cursor.getString(cursor.getColumnIndex("time"));
            String address = cursor.getString(cursor.getColumnIndex("address"));
            String phone = cursor.getString(cursor.getColumnIndex("des"));
            DormitoryBean dormitoryBean = new DormitoryBean(id,number1, name1,year, sex,birth,address,phone);
            list.add(dormitoryBean);
        }
        return list;
    }

    public static List<DormitoryBean> getDormitoryListByNumber(String number) {
        List<DormitoryBean> list = new ArrayList<>();
        String sql = "select * from dormitory where number="+number;
        Cursor cursor = db.rawQuery(sql, null);
        while (cursor.moveToNext()) {
            int id = cursor.getInt(cursor.getColumnIndex("id"));
            String number1 = cursor.getString(cursor.getColumnIndex("number"));
            String name = cursor.getString(cursor.getColumnIndex("name"));
            String year = cursor.getString(cursor.getColumnIndex("much"));
            String sex = cursor.getString(cursor.getColumnIndex("sex"));
            String birth = cursor.getString(cursor.getColumnIndex("time"));
            String address = cursor.getString(cursor.getColumnIndex("address"));
            String phone = cursor.getString(cursor.getColumnIndex("des"));
            DormitoryBean dormitoryBean = new DormitoryBean(id,number1, name,year, sex,birth,address,phone);
            list.add(dormitoryBean);
        }
        return list;
    }


    @Override
    public void onCreate(SQLiteDatabase db) {
        String sql = ("CREATE TABLE dormitory(id INTEGER PRIMARY KEY AUTOINCREMENT," +
                "number VARCHAR(50) not null," +
                "name VARCHAR(20) not null," +
                "much VARCHAR(2) not null," +
                "sex VARCHAR(2) not null," +
                "time varchar(60) not null," +
                "address Varchar(60) not null," +
                "des VARCHAR(11) not null)");

        db.execSQL(sql);
    }

    @Override
    public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion) {
        db.execSQL("drop table if exists dormitory");
        onCreate(db);
    }
    public void insertDormitory(String number,String name, String year, String sex, String birth,
                            String address,String phone) {
        db.execSQL("INSERT INTO dormitory(number,name,much,sex,time,address,des)VALUES(?,?,?,?,?,?,?)",
                new String[]{number,name,year,sex, birth,address,phone});
    }
    /**
     * 浏览
     * */
    public static List<DormitoryBean> search() {
        List<DormitoryBean> list = new ArrayList<>();
        String sql = "select * from dormitory order by number";
        Cursor cursor = db.rawQuery(sql, null);
        while (cursor.moveToNext()) {
            int id = cursor.getInt(cursor.getColumnIndex("id"));
            String number = cursor.getString(cursor.getColumnIndex("number"));
            String name = cursor.getString(cursor.getColumnIndex("name"));
            String year = cursor.getString(cursor.getColumnIndex("much"));
            String sex = cursor.getString(cursor.getColumnIndex("sex"));
            String birth = cursor.getString(cursor.getColumnIndex("time"));
            String address = cursor.getString(cursor.getColumnIndex("address"));
            String phone = cursor.getString(cursor.getColumnIndex("des"));
            DormitoryBean dormitoryBean = new DormitoryBean(id,number, name,year, sex,birth,address,phone);
            list.add(dormitoryBean);
        }
        return list;
    }
    public static int deleteItemFromDormitoryByNumber(String number) {
        int i = db.delete("dormitory", "number=?", new String[]{number + ""});
        return i;
    }
/**
 * 查询宿舍号是否存在
 * */
    public static DormitoryBean QueryFromDormitoryByNumber(String number) {
      //  List<dormitorysBean> list = new ArrayList<>();
        DormitoryBean dormitoryBean = null;
        String sql = "select * from dormitory where number ="+number;
        Cursor cursor = db.rawQuery(sql, null);
        while (cursor.moveToNext()) {
            int id = cursor.getInt(cursor.getColumnIndex("id"));
            String number1 = cursor.getString(cursor.getColumnIndex("number"));
            String name = cursor.getString(cursor.getColumnIndex("name"));
            String year = cursor.getString(cursor.getColumnIndex("much"));
            String sex = cursor.getString(cursor.getColumnIndex("sex"));
            String birth = cursor.getString(cursor.getColumnIndex("time"));
            String address = cursor.getString(cursor.getColumnIndex("address"));
            String phone = cursor.getString(cursor.getColumnIndex("des"));
            dormitoryBean = new DormitoryBean(id, number1, name, year, sex, birth, address, phone);
        //    list.add(dormitoryBean);
        }
        return dormitoryBean;
    }
    //修改数据
    public boolean updateDormitory(String number,String name,String much,String sex,String time,String address,String des){
        ContentValues contentValues=new ContentValues();
        contentValues.put("name",name);
        contentValues.put("much",much);
        contentValues.put("sex",sex);
        contentValues.put("time",time);
        contentValues.put("address",address);
        contentValues.put("des",des);
        String sql="number"+"=?";
        String[] strings=new String[]{number};
        return
                db.update("dormitory",contentValues,sql,strings)>0;
    }
}
