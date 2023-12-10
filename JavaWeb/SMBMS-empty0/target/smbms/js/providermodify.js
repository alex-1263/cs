var proContact = null;
var proPhone = null;
var saveBtn = null;
var backBtn = null;

$(function(){
	proContact = $("#proContact");
	proPhone = $("#proPhone");
	saveBtn = $("#save");
	backBtn = $("#back");
	
	//初始化的时候，要把所有的提示信息变为：* 以提示必填项，更灵活，不要写在页面上
	proContact.next().html("*");
	proPhone.next().html("*");

	$.ajax({
		type: "GET",//请求类型
		url: path + "/getProviderInfo",//请求的url
		data: {id: $("#id").val()},//请求参数
		dataType: "json",//ajax接口（请求url）返回的数据类型
		success: function (data) {//data：返回数据（json对象）
			if (data != null) {
				$("#proCode").attr("value", data.proCode);
				$("#proName").attr("value", data.proName);
				$("#proContact").attr("value", data.proContact);
				$("#proPhone").attr("value", data.proPhone);
				$("#proAddress").attr("value", data.proAddress);
				$("#proFax").attr("value", data.proFax);
				$("#proDesc").attr("value", data.proDesc);
			}
		},
		error: function (data) {//当访问时候，404，500 等非200的错误状态码
			validateTip($("#proDesc").next(), {"color": "red"}, imgNo + " 获取供应商信息error", false);
		}
	});

	/*
	 * 验证
	 * 失焦\获焦
	 * jquery的方法传递
	 */
	proContact.on("focus",function(){
		validateTip(proContact.next(),{"color":"#666666"},"* 请输入联系人",false);
	}).on("blur",function(){
		if(proContact.val() != null && proContact.val() != ""){
			validateTip(proContact.next(),{"color":"green"},imgYes,true);
		}else{
			validateTip(proContact.next(),{"color":"red"},imgNo+" 联系人不能为空，请重新输入",false);
		}
		
	});
	
	proPhone.on("focus",function(){
		validateTip(proPhone.next(),{"color":"#666666"},"* 请输入手机号",false);
	}).on("blur",function(){
		var patrn=/^(13[0-9]|15[0-9]|18[0-9])\d{8}$/;
		if(proPhone.val().match(patrn)){
			validateTip(proPhone.next(),{"color":"green"},imgYes,true);
		}else{
			validateTip(proPhone.next(),{"color":"red"},imgNo + " 您输入的手机号格式不正确",false);
		}
	});
	
	saveBtn.on("click",function(){
		proContact.blur();
		proPhone.blur();
		if(proContact.attr("validateStatus") == "true" && 
				proPhone.attr("validateStatus") == "true"){
			if(confirm("是否确认提交数据")){
				$("#providerForm").submit();
			}
		}
	});
	
	backBtn.on("click",function(){
		//alert("modify: "+referer);
		if(referer != undefined 
			&& null != referer 
			&& "" != referer
			&& "null" != referer
			&& referer.length > 4){
		 window.location.href = referer;
		}else{
			history.back(-1);
		}
	});
});