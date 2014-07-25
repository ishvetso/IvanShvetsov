host=username@server
ssh $host "echo 2>&1"
test $? -eq 0 && echo $host OK || echo $host NOK
