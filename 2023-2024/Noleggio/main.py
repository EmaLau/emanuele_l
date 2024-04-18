import csv
import mariadb
import sys


try:
    connection = mariadb.connect(user="root", password="", host="localhost", port=3306, database="Noleggio")
except mariadb.Error as e:
    print(e);
    sys.exit(1)



with open('noleggi.csv', newline='') as csvfile:
    spamreader = csv.reader(csvfile, delimiter=',', quotechar='|')
    for row in spamreader:
        print(row[0], row[1], row[2], row[3], row[4], row[5], row[6])
