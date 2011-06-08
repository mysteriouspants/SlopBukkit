#!/usr/bin/ruby

def t(m)
    ( 2 * Math::PI / 60 ) * m + ( Math::PI / 2 )
end

a = 0
b = 0
r = 1

def x(a, b, r, m)
    a + r * Math.cos(t(m))
end

def y(a, b, r, m)
    b + r * Math.sin(t(m))
end

m = 0
while m != 60
    puts "minute: #{m} x-value: #{x(a, b, r, m)} y-value: #{y(a, b, r, m)}"
    m += 1
end
