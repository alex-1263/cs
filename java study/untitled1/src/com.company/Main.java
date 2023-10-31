package com.company;

import dao.UserDao;
import entity.User;
import util.DBUtil;

import java.util.List;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        // write your code here
        /*DBUtil db = new DBUtil();
        boolean flag = db.getConnection();
        if (flag) {
            System.out.print("get connection success!");
        }
        db.closeResource();

        UserDao userdao = new UserDao();
        List<User> users = userdao.getAllUser();
        User user;
        for (int i = 0; i < users.size(); i++) {
            user = users.get(i);
            System.out.print(user.toString()+"\n");
        }*/
        UserDao userdao = new UserDao();
        System.out.println("请输入用户名和密码(用逗号分割):");
        Scanner sc = new Scanner(System.in);
        String input = sc.next();
        String s[] = input.split(",");
        boolean flag = userdao.loginUser(s[0], s[1]);
        if (flag){
            System.out.println("登录成功!");
        } else {
            System.out.println("登录失败!");
        }

    }
}
