from django.db import models

class Student(models.Model):
    first_name = models.CharField(max_length = 64)
    last_name = models.CharField(max_length = 64)
    fathers_name = models.CharField(max_length = 64)
    AIR = models.IntegerField()
    course = models.CharField(max_length = 64)
