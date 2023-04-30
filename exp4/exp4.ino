import random
import urllib.request
import urllib
import requests
import threading
import json

def Send_Data():
    threading.Timer(2,Send_Data).start()
    val = random.randint(1,50)
    URL="https://api.thingspeak.com/update?api_key=31HN79G7WTQRUEZF&field1=0"
    KEY="31HN79G7WTQRUEZF"
    HEADER='&field2={}'.format(val)
    new_URL=URL+KEY+HEADER
    print(new_URL)
    data = urllib.request.urlopen(new_URL)
    print(data)


def Read_Data():
    data_read = urllib.request.urlopen("https://api.thingspeak.com/channels/1303084/feeds.json?api_key=CMW0B4FKUOZW468K&results=2")
if _name_ == '_main_' :
    Send_Data()
