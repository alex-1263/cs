package com.digital.beans;

import java.util.Date;

public class User {
    private String username;
    private String password;
    private String realname;
    private String sex;
    private String address;
    private String question;
    private String answer;
    private String email;
    private Date time;
    private User user;

    public String getUsername() {
        return username;
    }

    public void setUsername(String username) {
        this.username = username;
    }

    public String getPassword() {
        return password;
    }

    public void setPassword(String password) {
        this.password = password;
    }

    public void setRealname(String realname) {
        this.realname = realname;
    }

    public void setSex(String sex) {
        this.sex = sex;
    }

    public void setAddress(String address) {
        this.address = address;
    }

    public void setQuestion(String question) {
        this.question = question;
    }

    public void setAnswer(String answer) {
        this.answer = answer;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public void setTime(Date time) {
        this.time = time;
    }

    public boolean addUser(User user) {
        this.user = user;
        return false;
    }


    public String getRealname() {
        return realname;
    }

    public String getSex() {
        return sex;
    }

    public String getAddress() {
        return address;
    }

    public String getQuestion() {
        return question;
    }

    public String getAnswer() {
        return answer;
    }

    public String getEmail() {
        return email;
    }

    public Date getTime() {
        return time;
    }

    public User getUser() {
        return user;
    }

    public void setUser() {
        setUser(null);
    }

    public void setUser(User user) {
        this.user = user;
    }
}
