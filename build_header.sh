find src -name '*.h' | awk '{print "#include\""$1"\""}' > all.h
