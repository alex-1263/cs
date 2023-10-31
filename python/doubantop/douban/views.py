from django.shortcuts import render
from douban import doubanDao
# Create your views here.
from django.http import JsonResponse
from django.db import connection
import json
# 主视图 返回index页面
def index(request):
    mycursor=connection.cursor()
    sql="select name,rate from movie order by rate DESC limit 7"
    mycursor.execute(sql)
    data=mycursor.fetchall()
    print(data)
    return render(request, 'index.html',{'data':data})
def length(request):
    name=doubanDao.getname()
    return JsonResponse(name,safe=False,json_dumps_params={'ensure_ascii':False})
def year(request):
    year=doubanDao.getyear()
    return JsonResponse(year,safe=False,json_dumps_params={'ensure_ascii':False})
def getgenres(request):
    genres=doubanDao.getgenres
    print(genres)
    return JsonResponse(genres,safe=False,json_dumps_params={'ensure_ascii':False})