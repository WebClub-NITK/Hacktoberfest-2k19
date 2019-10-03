from django.shortcuts import render
from django.http import HttpResponseRedirect, HttpResponse

from .models import Student

from . import views

def register(request):
    if request.method != 'POST':
        return HttpResponseRedirect(reverse("index"))

    #Take form info
    first_name = request.POST["first_name"]
    last_name = request.POST["last_name"]
    fathers_name = request.POST["fathers_name"]
    AIR = request.POST["AIR"]
    course = request.POST["course"]
    #Save the form info
    student = Student(first_name = first_name, last_name = last_name, fathers_name = fathers_name, AIR = AIR, course = course)
    student.save()

    return HttpResponse("Successfully Registered")

def index(request):
    return render(request, "student/index.html")
