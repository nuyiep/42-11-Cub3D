MAPDIR="maps/codequoi/bad"
EXE="./cub3d"
export Reset='\033[0m'
export Bold='\033[1m'
export Underline='\033[4m'
export Blinking='\033[5m'
export Inverse='\033[7m'
export Black='\033[30m'
export Red='\033[31m'
export Green='\033[32m'
export Yellow='\033[33m'
export Blue='\033[34m'
export Magenta='\033[35m'
export Cyan='\033[36m'
export White='\033[37m'

make || exit 1

for map in $MAPDIR/*
do
	# echo map: $map
	"$EXE" "$map" &
	pid=$!
	{
		sleep 4
		kill $pid 2>/dev/null # Suppress error output if process has already completed
	} &
	error=""
	wait $pid
	status=$?
	case $status in
		1)
			error="ok"
			;;
		138)
			error="Bus error"
			;;
		139)
			error="Seg fault"
			;;
		143)
			error="Timeout"
			;;
		0)
			error="Missing Error"
			;;
		*)
			error="Unknown Error: $status"
			;;
	esac
	if [ "$error" == 'ok' ]
	then
		echo -e "$Green$map$Reset"
	else
		echo -e "$Red$map$Reset"
	fi
done
