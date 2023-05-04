
writefile=$1
writestr=$2

if [ -z $writefile ] || [ -z $writestr ]; then
    echo "Missing parameters"
    exit 1
fi

path=${writefile%/*}/

mkdir -p $path

echo $writestr > $writefile

