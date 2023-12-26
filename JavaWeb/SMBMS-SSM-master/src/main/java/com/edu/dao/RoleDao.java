package com.edu.dao;

import com.edu.pojo.Role;
import org.springframework.stereotype.Repository;

import java.util.List;

@Repository
public interface RoleDao {

    public List<Role> getRoleList();

}
