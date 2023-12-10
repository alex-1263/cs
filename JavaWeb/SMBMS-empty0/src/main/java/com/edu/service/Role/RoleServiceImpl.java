package com.edu.service.Role;

import com.edu.dao.RoleMapper;
import com.edu.pojo.Role;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class RoleServiceImpl implements RoleService{

    @Autowired
   RoleMapper roleMapper;
    @Override
    public List<Role> queryRole() {
        return roleMapper.queryRole();
    }
}
