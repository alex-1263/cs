package com.edu.service.user;

import com.edu.dao.UserMapper;
import com.edu.pojo.Bill;
import com.edu.pojo.User;
import com.edu.service.user.UserService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class UserServicelmpl implements UserService {

    @Autowired
    UserMapper userMapper;

    @Override
    public User getUserByCodeAndpwd(String userCode, String password) {
        return userMapper.getUserByCodeAndpwd(userCode, password);
    }

    @Override
    public List<User> usermanage(String userName, Integer userRole) {
        return userMapper.usermanage(userName, userRole);
    }

    @Override
    public User getUserByCode(String userCode) {
        return userMapper.getUserByCode(userCode);
    }

    @Override
    public int inserUser(User user) {
        return userMapper.addUser(user);
    }


}
