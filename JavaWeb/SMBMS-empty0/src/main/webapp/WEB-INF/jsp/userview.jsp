<%@ page language="java" contentType="text/html; charset=UTF-8"
         pageEncoding="UTF-8"%>
<%@include file="head.jsp"%>
 <div class="right">
        <div class="location">
            <strong>你现在所在的位置是:</strong>
            <span>用户管理页面 >> 用户信息查看页面</span>
        </div>
     <div class="providerAdd">
     <form id="userForm" name="userForm">
         <input type="hidden" name="uid" id="uid" value="${uid}"/>
         <div>
             <label for="userName">用户名称：</label>
             <input type="text" name="userName" id="userName" disabled>
         </div>
         <div>
             <label >用户性别：</label>
             <select name="gender" id="gender" disabled>
                 <option value="1" selected="selected">男</option>
                 <option value="2">女</option>
             </select>
         </div>
         <div>
             <label id="data">出生日期：</label>
             <input type="text" Class="Wdate" id="birthday" name="birthday" disabled>
             <font color="red"></font>
         </div>

         <div>
             <label id="userphone">用户电话：</label>
             <input type="text" name="phone" id="phone" disabled>
         </div>
         <div>
             <label id="userAddress">用户地址：</label>
             <input type="text" name="address" id="address" disabled>
         </div>
         <div>
             <label >用户角色：</label>
             <!-- 列出所有的角色分类 -->
             <select name="userRole" id="userRole" disabled></select>
             <font color="red"></font>
         </div>
         <div class="providerAddBtn">
             <input type="button" id="back" name="back" value="返回" >
         </div>
     </form>
    </div>
</div>
</section>
<%@include file="foot.jsp" %>
<script type="text/javascript" src="${pageContext.request.contextPath }/js/userview.js"></script>