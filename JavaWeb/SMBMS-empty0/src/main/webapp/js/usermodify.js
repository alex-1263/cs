var userName = null;
var birthday = null;
var phone = null;
var userRole = null;
var saveBtn = null;
var backBtn = null;
var codeValid = null;
var nameValid = null;
var pwdValid = null;
var birthdayValid = null;
var phoneValid = null;
var roleValid = null;

$(function () {
    userName = $("#userName");
    birthday = $("#birthday");
    phone = $("#phone");
    userRole = $("#userRole");
    saveBtn = $("#save");
    backBtn = $("#back");

    userName.next().html("*");
    birthday.next().html("*");
    phone.next().html("*");
    userRole.next().html("*");

    $.ajax({
        type: "GET",//请求类型
        url: path + "/getRoleList",//请求的url
        dataType: "json",//ajax接口（请求url）返回的数据类型
        success: function (data) {//data：返回数据（json对象）
            if (data != null) {
                // var rid = $("#rid").val();
                userRole.html("");
                var options = "<option value=\"0\">请选择</option>";
                for (var i = 0; i < data.length; i++) {
                    options += "<option value=\"" + data[i].id + "\" >" + data[i].roleName + "</option>";
                }
                userRole.html(options);
            }
        },
        error: function (data) {//当访问时候，404，500 等非200的错误状态码
            validateTip(userRole.next(), {"color": "red"}, imgNo + " 获取用户角色列表error", false);
        }
    });

    $.ajax({
        type: "GET",//请求类型
        url: path + "/getUserInfo",//请求的url
        data: {id: $("#id").val()},//请求参数
        dataType: "json",//ajax接口（请求url）返回的数据类型
        success: function (data) {//data：返回数据（json对象）
            if (data != null) {
                $("#userName").attr("value", data.userName);
                $("#gender").attr("value", data.gender);
                const date = new Date(data.birthday);
                $("#birthday").attr("value", date.getFullYear() + "-" + (date.getMonth() + 1) + "-" + date.getDate());
                $("#phone").attr("value", data.phone);
                $("#address").attr("value", data.address);
                $("#userRole").val(data.userRole);
            }
        },
        error: function (data) {//当访问时候，404，500 等非200的错误状态码
            validateTip(userRole.next(), {"color": "red"}, imgNo + " 获取用户信息error", false);
        }
    });

    userName.on("focus", function () {
        validateTip(userName.next(), {"color": "#666666"}, "* 用户名长度必须是大于1小于10的字符", false);
    }).on("blur", function () {
        if (userName.val() != null && userName.val().length > 1
            && userName.val().length < 10) {
            nameValid = true;
            validateTip(userName.next(), {"color": "green"}, imgYes, true);
        } else {
            nameValid = false;
            validateTip(userName.next(), {"color": "red"}, imgNo + " 用户名输入的不符合规范，请重新输入", false);
        }

    });

    birthday.on("focus", function () {
        validateTip(birthday.next(), {"color": "#666666"}, "* 点击输入框，选择日期", false);
    }).on("blur", function () {
        if (birthday.val() != null && birthday.val() != "") {
            birthdayValid = true;
            validateTip(birthday.next(), {"color": "green"}, imgYes, true);
        } else {
            birthdayValid = false;
            validateTip(birthday.next(), {"color": "red"}, imgNo + " 选择的日期不正确,请重新输入", false);
        }
    });

    phone.on("focus", function () {
        validateTip(phone.next(), {"color": "#666666"}, "* 请输入手机号", false);
    }).on("blur", function () {
        var patrn = /^(13[0-9]|15[0-9]|18[0-9])\d{8}$/;
        if (phone.val().match(patrn)) {
            phoneValid = true;
            validateTip(phone.next(), {"color": "green"}, imgYes, true);
        } else {
            phoneValid = false;
            validateTip(phone.next(), {"color": "red"}, imgNo + " 您输入的手机号格式不正确", false);
        }
    });

    userRole.on("focus", function () {
        validateTip(userRole.next(), {"color": "#666666"}, "* 请选择用户角色", false);
    }).on("blur", function () {
        if (userRole.val() != null && userRole.val() > 0) {
            roleValid = true;
            validateTip(userRole.next(), {"color": "green"}, imgYes, true);
        } else {
            roleValid = false;
            validateTip(userRole.next(), {"color": "red"}, imgNo + " 请重新选择用户角色", false);
        }

    });

    saveBtn.on("click", function () {
        if ((nameValid == null && userName.val() == "") || nameValid == false) {
            alert("用户名称输入非法");
            userName.blur();
        } else if ((birthdayValid == null && birthday.val() == "") || birthdayValid == false) {
            alert("用户生日输入非法");
            birthday.blur();
        } else if ((phoneValid == null && phone.val() == "") || phoneValid == false) {
            alert("用户手机输入非法");
            phone.blur();
        } else if ((roleValid == null && userRole.val() == "") || roleValid == false) {
            alert("用户角色输入非法");
            userRole.blur();
        } else {
            if (confirm("是否确认提交数据")) {
                $("#userForm").submit();
            }
        }
    });

    backBtn.on("click", function () {
        //alert("modify: "+referer);
        if (referer != undefined
            && null != referer
            && "" != referer
            && "null" != referer
            && referer.length > 4) {
            window.location.href = referer;
        } else {
            history.back(-1);
        }
    });
});