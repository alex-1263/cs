package com.edu.dao;

import com.edu.pojo.Role;
import org.apache.ibatis.annotations.Param;

import java.util.List;

public interface RoleMapper {
    public List<Role>queryRole();
}
