#    NETWORKING
'''
URL and IMAGES from urllib
SOCKET PROGRAMMING from socket
SEND EMAILS from smtlib
'''
# Acces url and downloading html
import urllib.request

try:
    url = urllib.request.urlopen('https://www.python.org/')
    content = url.read()
    url.close()
except urllib.error.HTTPError:
    print("Page not found!")
    exit()

f = open("python.html", 'wb')
f.write(content)
f.close()
