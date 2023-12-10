package com.edu.servlet;

import com.alibaba.fastjson.JSONArray;
import com.edu.pojo.Role;
import com.edu.pojo.User;
import com.edu.service.Role.RoleService;
import com.edu.service.user.UserService;
import com.edu.tools.Constants;
import com.edu.tools.ConvertUtil;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Date;
import java.util.HashMap;
import java.util.List;

@Controller
public class UserController {

    @Autowired
    UserService userService;
    @Autowired
    RoleService roleService;

    @RequestMapping("/login")
    public String longin(HttpServletRequest request, String userCode, String userPassword) {
        User user = userService.getUserByCodeAndpwd(userCode, userPassword);

        if (user != null) {
//            request.setAttribute(Constants.USER_SESSION,user);
            request.getSession().setAttribute(Constants.USER_SESSION, user);
            return "frame";
        }
        request.setAttribute("error", "用户名或密码有误！");
        return "login";
    }

    @RequestMapping("/logout.do")
    public String logout(HttpServletRequest request, HttpServletResponse response) {
        request.getSession().removeAttribute(Constants.USER_SESSION);
        return "login";
    }

    @RequestMapping("/queryUser")
    public String user(HttpServletRequest request, String queryname, Integer queryUserRole) {
        List<User> userList = userService.usermanage(queryname, queryUserRole);
        List<Role> roleList = roleService.queryRole();
        request.setAttribute("userList", userList);
        request.setAttribute("roleList", roleList);
        request.setAttribute("queryname", queryname);
        request.setAttribute("queryUserRole", queryUserRole);
        return "userlist";
    }

    @RequestMapping("/userExisted")
    public void userExisted(HttpServletResponse response, String userCode) throws IOException {
        User user = userService.getUserByCode(userCode);
        HashMap<String, String> map = new HashMap<>();

        if (user != null) {
            map.put("userCode", "exist");
        }
        response.setContentType("application/json");
        PrintWriter printWriter = response.getWriter();
        String jsonStr = JSONArray.toJSONString(map);
        printWriter.write(jsonStr);
        printWriter.flush();

    }
    @RequestMapping("/getRoleList")
    public void getRoleList(HttpServletResponse response) throws IOException {
        List<Role> roleList = roleService.queryRole();
        String jsonStr = JSONArray.toJSONString(roleList);
       ConvertUtil.sendJsonnMsg(response,jsonStr);
    }

    @RequestMapping("/addUser")
    public String addUser(HttpServletRequest request, User user){
        User currentUser = (User)request.getSession().getAttribute(Constants.USER_SESSION);
        user.setCreatedBy(currentUser.getId());
        user.setCreationDate(new Date());
        int result = userService.inserUser(user);
        if (result > 0){
            return "redirect:/queryUser";
        }
        return "useradd";
    }
}
