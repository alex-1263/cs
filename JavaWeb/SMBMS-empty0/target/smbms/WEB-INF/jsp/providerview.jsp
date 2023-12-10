<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@include file="head.jsp"%>
 <div class="right">
        <div class="location">
            <strong>你现在所在的位置是:</strong>
            <span>供应商管理页面 >> 信息查看</span>
        </div>
        <div class="providerAdd">
          <form id="providerForm" name="providerForm">
              <input type="hidden" name="id" id="id" value="${proid}"/>
              <!--div的class 为error是验证错误，ok是验证成功-->
              <div class="">
                  <label for="proCode">供应商编码：</label>
                  <input type="text" name="proCode" id="proCode" readonly="readonly" disabled>
              </div>
              <div>
                  <label for="proName">供应商名称：</label>
                 <input type="text" name="proName" id="proName" disabled>
			<font color="red"></font>
              </div>
              
              <div>
                  <label for="proContact">联系人：</label>
                  <input type="text" name="proContact" id="proContact" disabled>
			<font color="red"></font>
              </div>
              
              <div>
                  <label for="proPhone">联系电话：</label>
                  <input type="text" name="proPhone" id="proPhone" disabled>
			<font color="red"></font>
              </div>
              
              <div>
                  <label for="proAddress">联系地址：</label>
                  <input type="text" name="proAddress" id="proAddress" disabled>
              </div>
              
              <div>
                  <label for="proFax">传真：</label>
                  <input type="text" name="proFax" id="proFax" disabled>
              </div>
              
              <div>
                  <label for="proDesc">描述：</label>
                  <input type="text" name="proDesc" id="proDesc" disabled>
              </div>
              <div class="providerAddBtn">
				  <input type="button" id="back" name="back" value="返回" >
              </div>
          </form>
        </div>
    </div>
</section>
<%@include file="foot.jsp" %>
<script type="text/javascript" src="${pageContext.request.contextPath }/js/providerview.js"></script>
