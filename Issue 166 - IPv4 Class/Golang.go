package main

import (
	"fmt"
	"strconv"
  "strings"
)

func findIPClass(ipAdd string)byte{
  ip := strings.Split(ipAdd, ".") 
  if(len(ip) == 4){
    first, err1 := strconv.Atoi(ip[0])
    second, err2 := strconv.Atoi(ip[1])
    third, err3 := strconv.Atoi(ip[2])
    fourth, err4 := strconv.Atoi(ip[3])

    if(err1 == nil && err2 == nil && err3 == nil && err4 == nil){
      if(first >= 0 && first <= 127){
        if((second >= 0 && second <= 255) && (third >= 0 && third <= 255) && (fourth >= 0 && fourth <= 255)){
          return 'A'
        }else{
          return 'N'
        }
      }else if(first >= 128 && first <= 191){
        if((second >= 0 && second <= 255) && (third >= 0 && third <= 255) && (fourth >= 0 && fourth <= 255)){
          return 'B'
        }else{
          return 'N'
        }
      }else if(first >= 192 && first <= 223){
        if((second >= 0 && second <= 255) && (third >= 0 && third <= 255) && (fourth >= 0 && fourth <= 255)){
          return 'C'
        }else{
          return 'N'
        }
      }else if(first >= 224 && first <= 239){
        if((second >= 0 && second <= 255) && (third >= 0 && third <= 255) && (fourth >= 0 && fourth <= 255)){
          return 'D'
        }else{
          return 'N'
        }
      }else if(first >= 240 && first <= 255){
        if((second >= 0 && second <= 255) && (third >= 0 && third <= 255) && (fourth >= 0 && fourth <= 255)){
          return 'E'
        }else{
          return 'N'
        }
      }
      return 'N'
    }
    return 'N'
  }
  return 'N'
}

func main() {
  fmt.Print("Enter the IPv4 address: ")
    var input string
    fmt.Scanln(&input)
  var class byte= findIPClass(input)
  if(class != 'N'){
    fmt.Printf("This is a class %c IPv4 address.\n", class)
  }else{
    fmt.Printf("This IPv4 address is inappropriate hence class cannot be found\n")
  }
}