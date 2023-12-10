var userCode = null;
var userName = null;
var userPassword = null;
var phone = null;
var birthday = null;
var userRole = null;
var addBtn = null;
var backBtn = null;
var codeValid = null;
var nameValid = null;
var pwdValid = null;
var birthdayValid = null;
var phoneValid = null;
var roleValid = null;


$(function(){
	userCode = $("#userCode");
	userName = $("#userName");
	userPassword = $("#userPassword");
	phone = $("#phone");
	birthday = $("#birthday");
	userRole = $("#userRole");
	addBtn = $("#add");
	backBtn = $("#back");

	//初始化的时候，要把所有的提示信息变为：* 以提示必填项，更灵活，不要写在页面上
	userCode.next().html("*");
	userName.next().html("*");
	userPassword.next().html("*");
	phone.next().html("*");
	birthday.next().html("*");
	userRole.next().html("*");

	$.ajax({
		type:"GET",//请求类型
		url:path+"/getRoleList",//请求的url
		dataType:"json",//ajax接口（请求url）返回的数据类型
		success:function(data){//data：返回数据（json对象）
			roleValid = true;
			if(data != null){
				userRole.html("");
				var options = "<option value=\"0\">请选择</option>";
				for(var i = 0; i < data.length; i++){
					//alert(data[i].id);
					//alert(data[i].roleName);
					options += "<option value=\""+data[i].id+"\">"+data[i].roleName+"</option>";
				}
				userRole.html(options);
			}
		},
		error:function(data){//当访问时候，404，500 等非200的错误状态码
			roleValid = false;
			validateTip(userRole.next(),{"color":"red"},imgNo+" 获取用户角色列表error",false);
		}
	});

	/*
	 * 验证
	 * 失焦\获焦
	 * jquery的方法传递
	 */
	userCode.bind("blur",function(){
		if(userCode.val() == null || userCode.val() == ""){
			codeValid = false;
			validateTip(userCode.next(),{"color":"red"},imgNo+"编码不能为空，请重新输入",false);
			return;
		}
		//ajax后台验证--userCode是否已存在
		$.ajax({
			type:"GET",//请求类型
			url:path+"/userExisted",//请求的url
			data:{userCode:userCode.val()},//请求参数
			dataType:"json",//ajax接口（请求url）返回的数据类型
			success:function(data){//data：返回数据（json对象）
				if(data.userCode == "exist"){//账号已存在，错误提示
					codeValid = false;
					validateTip(userCode.next(),{"color":"red"},imgNo+ " 该用户账号已存在",false);
				}else{//账号可用，正确提示
					codeValid = true;
					validateTip(userCode.next(),{"color":"green"},imgYes+" 该账号可以使用",true);
				}
			},
			error:function(data){//当访问时候，404，500 等非200的错误状态码
				codeValid = false;
				validateTip(userCode.next(),{"color":"red"},imgNo+" 您访问的页面不存在",false);
			}
		});


	}).bind("focus",function(){
		//显示友情提示
		validateTip(userCode.next(),{"color":"#666666"},"* 用户编码是您登录系统的账号",false);
	}).focus();

	userName.bind("focus",function(){
		validateTip(userName.next(),{"color":"#666666"},"* 用户名长度必须是大于1小于10的字符",false);
	}).bind("blur",function(){
		if(userName.val() != null && userName.val().length > 1
				&& userName.val().length < 10){
			nameValid = true;
			validateTip(userName.next(),{"color":"green"},imgYes,true);
		}else{
			nameValid = false;
			validateTip(userName.next(),{"color":"red"},imgNo+" 用户名输入的不符合规范，请重新输入",false);
		}

	});

	userPassword.bind("focus",function(){
		validateTip(userPassword.next(),{"color":"#666666"},"* 密码长度必须是大于6小于20",false);
	}).bind("blur",function(){
		if(userPassword.val() != null && userPassword.val().length > 6
				&& userPassword.val().length < 20 ){
			pwdValid = true;
			validateTip(userPassword.next(),{"color":"green"},imgYes,true);
		}else{
			pwdValid = false;
			validateTip(userPassword.next(),{"color":"red"},imgNo + " 密码输入不符合规范，请重新输入",false);
		}
	});


	birthday.bind("focus",function(){
		validateTip(birthday.next(),{"color":"#666666"},"* 点击输入框，选择日期",false);
	}).bind("blur",function(){
		if(birthday.val() != null && birthday.val() != ""){
			birthdayValid = true;
			validateTip(birthday.next(),{"color":"green"},imgYes,true);
		}else{
			birthdayValid = false;
			validateTip(birthday.next(),{"color":"red"},imgNo + " 选择的日期不正确,请重新输入",false);
		}
	});

	phone.bind("focus",function(){
		validateTip(phone.next(),{"color":"#666666"},"* 请输入手机号",false);
	}).bind("blur",function(){
		var patrn=/^(13[0-9]|15[0-9]|18[0-9])\d{8}$/;
		if(phone.val().match(patrn)){
			phoneValid = true;
			validateTip(phone.next(),{"color":"green"},imgYes,true);
		}else{
			phoneValid = false;
			validateTip(phone.next(),{"color":"red"},imgNo + " 您输入的手机号格式不正确",false);
		}
	});

	userRole.bind("focus",function(){
		validateTip(userRole.next(),{"color":"#666666"},"* 请选择用户角色",false);
	}).bind("blur",function(){
		if(userRole.val() != null && userRole.val() > 0){
			roleValid = true;
			validateTip(userRole.next(),{"color":"green"},imgYes,true);
		}else{
			roleValid = false;
			validateTip(userRole.next(),{"color":"red"},imgNo + " 请重新选择用户角色",false);
		}
	});

	addBtn.bind("click",function(){
		if((codeValid==null && userCode.val()=="") || codeValid==false){
			alert("用户编码输入非法");
			userCode.focus();
		}else if((nameValid==null && userName.val()=="") || nameValid==false){
			alert("用户名称输入非法");
			userName.blur();
		}else if((pwdValid==null && userPassword.val()=="") || pwdValid==false){
            alert("用户密码输入非法");
			userPassword.blur();
		}else if((birthdayValid==null && birthday.val()=="")  || birthdayValid==false){
            alert("用户生日输入非法");
			birthday.blur();
		}else if((phoneValid==null && phone.val()=="")  || phoneValid==false){
            alert("用户手机输入非法");
			phone.blur();
		}else if((roleValid==null && userRole.val()=="")  || roleValid==false){
            alert("用户角色输入非法");
			userRole.blur();
		}else{
			if(confirm("是否确认提交数据")){
				$("#userForm").submit();
			}
		}
	});

	backBtn.on("click",function(){
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