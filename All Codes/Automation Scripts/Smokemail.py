import requests
from bs4 import BeautifulSoup
import smtplib
import time
import sys

def send_mail():
	server = smtplib.SMTP("smtp.gmail.com",587)
	server.ehlo()
	server.starttls()
	server.ehlo()
	server.login("rachity@gmail.com","vdgaikrfjhgmbswi")

	subject="Fire in the HOUSE"
	body="Urgent, call the fire Department, there is a fire at your place."


	msg=f"Subject: {subject}\n\n\n{body}"
	server.sendmail('rachity@gmail.com','rachity@gmail.com',msg)
	print("Mail has been sent")
	server.quit()


send_mail()

'''
sensor_value=sys.argv[1]
while(sensor_value=='HIGH'):
	send_mail()
	time.sleep(60)
'''