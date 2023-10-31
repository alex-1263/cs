import re
from django.db import connection

def getname():
    mycursor=connection.cursor()
    sql="select name,length from movie order by length DESC limit 10"
    mycursor.execute(sql)
    data=mycursor.fetchall()
    data2=[row[0] for row in data]
    data3=[row[1] for row in data]
    return [data2,data3]

def getyear():
    mycursor=connection.cursor()
    sql="SELECT YEAR,COUNT(*)  FROM movie GROUP BY YEAR ORDER BY COUNT(*) DESC LIMIT 10"
    mycursor.execute(sql)
    data=mycursor.fetchall()
    data2=[row[0] for row in data]
    data3=[row[1] for row in data]
    return [data2,data3]
def getgenres():
    mycursor=connection.cursor()
    sql="SELECT genres,COUNT(*)  FROM movie GROUP BY genres ORDER BY COUNT(*) DESC LIMIT 5"
    mycursor.execute(sql)
    data=mycursor.fetchall()
    data2=[row[0] for row in data]
    data3=[row[1] for row in data]
    return [data2,data3]