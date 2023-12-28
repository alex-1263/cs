package com.ljx.susheguanli.entity;

public class DormitoryBean {
    int id;
    String number;
    String name;
    String much;
    String sex;
    String time;
    String address;
    String des;


    public DormitoryBean(int id, String number, String name, String much, String sex, String time, String address, String des) {
        this.id = id;
        this.number = number;
        this.name = name;
        this.much = much;
        this.sex = sex;
        this.time = time;
        this.address = address;
        this.des = des;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getNumber() {
        return number;
    }

    public void setNumber(String number) {
        this.number = number;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getMuch() {
        return much;
    }

    public void setMuch(String much) {
        this.much = much;
    }

    public String getSex() {
        return sex;
    }

    public void setSex(String sex) {
        this.sex = sex;
    }

    public String getTime() {
        return time;
    }

    public void setTime(String time) {
        this.time = time;
    }

    public String getAddress() {
        return address;
    }

    public void setAddress(String address) {
        this.address = address;
    }

    public String getDes() {
        return des;
    }

    public void setDes(String des) {
        this.des = des;
    }

    @Override
    public String toString() {
        return "DormitoryBean{" +
                "id=" + id +
                ", number='" + number + '\'' +
                ", name='" + name + '\'' +
                ", much='" + much + '\'' +
                ", sex='" + sex + '\'' +
                ", time='" + time + '\'' +
                ", address='" + address + '\'' +
                ", des='" + des + '\'' +
                '}';
    }

    public DormitoryBean() {

    }
}

