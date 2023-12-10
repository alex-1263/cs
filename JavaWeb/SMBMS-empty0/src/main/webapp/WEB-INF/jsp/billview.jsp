<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@include file="head.jsp"%>
<div class="right">
     <div class="location">
         <strong>你现在所在的位置是:</strong>
         <span>订单管理页面 >> 信息查看</span>
     </div>
        <div class="providerAdd">
          <form id="billForm" name="billForm">
				<input type="hidden" name="id" id="id" value="${billId}">
                <!--div的class 为error是验证错误，ok是验证成功-->
                <div class="">
                    <label for="billCode">订单编码：</label>
                    <input type="text" name="billCode" id="billCode" readonly="readonly" disabled>
                </div>
                <div>
                    <label for="productName">商品名称：</label>
                    <input type="text" name="productName" id="productName" disabled>
					<font color="red"></font>
                </div>
                <div>
                    <label for="productUnit">商品单位：</label>
                    <input type="text" name="productUnit" id="productUnit" disabled>
					<font color="red"></font>
                </div>
                <div>
                    <label for="productCount">商品数量：</label>
                    <input type="text" name="productCount" id="productCount" disabled>
					<font color="red"></font>
                </div>
                <div>
                    <label for="totalPrice">总金额：</label>
                    <input type="text" name="totalPrice" id="totalPrice" disabled>
					<font color="red"></font>
                </div>
                <div>
                    <label for="providerId">供应商：</label>
                    <input type="hidden" id="pid" />
					<select name="providerId" id="providerId" disabled>
		        	</select>
					<font color="red"></font>
                </div>
                <div>
                    <label >是否付款：</label>
<%--                    <c:if test="${bill.isPayment == 1 }">--%>
						<input type="radio" name="isPayment" value="1" checked="checked" disabled>未付款
						<input type="radio" name="isPayment" value="2"  disabled>已付款
<%--					</c:if>--%>
<%--					<c:if test="${bill.isPayment == 2 }">--%>
<%--						<input type="radio" name="isPayment" value="1">未付款--%>
<%--						<input type="radio" name="isPayment" value="2" checked="checked">已付款--%>
<%--					</c:if>--%>
                </div>
                <div class="providerAddBtn">
				  <input type="button" id="back" name="back" value="返回" >
              	</div>
            </form>
        </div>

    </div>
</section>
<%@include file="foot.jsp" %>
<script type="text/javascript" src="${pageContext.request.contextPath }/js/billview.js"></script>