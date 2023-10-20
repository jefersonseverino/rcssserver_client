
# Goalie

./player goalie &
sleep 1

for player in {2..11}
do
    ./player &
    sleep 1
done
