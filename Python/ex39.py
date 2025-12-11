#import urllib
#import urllib.request
from urllib import request

target = request.urlopen('https://google.com').read()

print(target)
