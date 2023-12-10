<%@ page language="java" contentType="text/html; charset=UTF-8"
         pageEncoding="UTF-8" %>
<%--<%@taglib prefix="fm" uri="http://www.springframework.org/tags/form" %>--%>
<%@include file="head.jsp" %>

<div class="right">
    <div class="location">
        <strong>你现在所在的位置是:</strong>
        <span>用户管理页面 >> 用户添加页面</span>
    </div>
    <div class="providerAdd">
        <form id="userForm" name="userForm" action="${pageContext.request.contextPath}/addUser" method="post">
            <div>
                <label for="userCode">用户编码：</label>
                <input id="userCode" name="userCode" type="text"/>

                <!-- 放置提示信息 -->
                <font color="red"></font>
            </div>
            <div>
                <label for="userName">用户名称：</label>
                <input id="userName" name="userName" type="text"/>

                <font color="red"></font>
            </div>
            <div>
                <label for="userPassword">用户密码：</label>
                <input id="userPassword" name="userPassword" type="password"/>

                <font color="red"></font>
            </div>
            <div>
                <label>用户性别：</label>
                <select id="gender" name="gender">
                    <option value="1" selected="selected">男</option>
                    <option value="2">女</option>
                </select>

            </div>
            <div>
                <label for="birthday">出生日期：</label>
                <input id="birthday" name="birthday" readonly=true onclick="WdatePicker();" Class="Wdate" type="text"/>

                <font color="red"></font>
            </div>
            <div>
                <label for="phone">用户电话：</label>
                <input id="phone" name="phone" type="text"/>

                <font color="red"></font>
            </div>
            <div>
                <label for="address">用户地址：</label>
                <input id="address" name="address" type="text"/>

            </div>
            <div>
                <label>用户角色：</label>
                <!-- 列出所有的角色分类 -->
                <select id="userRole" name="userRole">
                    <%--                        <option value="1">系统管理员</option>--%>
                    <%--                        <option value="2">经理</option>--%>
                    <%--                        <option value="3">普通用户</option>--%>
                </select>

                <font color="red"></font>
            </div>
            <div class="providerAddBtn">
                <input type="button" name="add" id="add" value="保存">
                <input type="button" id="back" name="back" value="返回">
            </div>
        </form>
    </div>
</div>
</section>
<%@include file="foot.jsp" %>
<script type="text/javascript" src="${pageContext.request.contextPath }/js/useradd.js"></script>
