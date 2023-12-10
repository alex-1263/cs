package com.edu.dao;

import com.edu.pojo.Provider;
import com.edu.pojo.User;
import org.apache.ibatis.annotations.Param;

import java.util.List;

public interface UserMapper {
    User getUserByCodeAndpwd(@Param("userCode") String userCode, @Param("password") String password);

    public List<User> usermanage(@Param("userName") String userName, @Param("userRole") Integer userRole);

    User getUserByCode(String userCode);

    int addUser(User user);
}
