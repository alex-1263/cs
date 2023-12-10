package com.edu.service.user;

import com.edu.pojo.User;

import java.util.List;

public interface UserService {
    User getUserByCodeAndpwd(String userCode, String userPassword);
    public List<User> usermanage(String userName,Integer userRole);
    User getUserByCode(String userCode);
    int inserUser(User user);
}
