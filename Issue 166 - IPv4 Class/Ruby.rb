True = true
print "Enter the IPv4 address: "
ip = gets.chomp.split(".")

while True
    begin
        ip0 = Integer(ip.at(0))
        ip1 = Integer(ip.at(1))
        ip2 = Integer(ip.at(2))
        ip3 = Integer(ip.at(3))
        True = nil
    rescue
        puts "Error: Invalid IPv4 address (Must have just numbers)."
        print "Enter the IPv4 address: "
        ip = gets.chomp.split(".")
    end
end

result = case ip0
    when 001 .. 126 then "This is a class A IPv4 address."
    when 127 then "This is a loopback IPv4 address."
    when 128 .. 191 then "This is a class B IPv4 address."
    when 192 .. 223 then "This is a class C IPv4 address."
    when 224 .. 239 then "This is a class D IPv4 address."
    when 240 .. 255 then "This is a class E IPv4 address."
    else "Error: Invalid IPv4 address."
end

if  (ip1 < 256 && -1 < ip1 && ip2 < 256 && -1 < ip2 && ip3 < 256 && -1 < ip3)  
    puts result
else 
    puts "Error: Invalid IPv4 address (It can't be bigger than 255 and smaller than 0)."
end

print "Enter for end..."
ip = gets.chomp