IDBLOADER=./rk3566_tool/idbloader.img
UBOOT=uboot.img
#TRUST=trust.img

if [ -z $1 ]; then
        echo "Usage ./sd_fusing.sh <SD card reader's device>"
        exit 1
fi
#cat ./rk356x_spl_loader_v1.07.111.bin >> $IDBLOADER
#sudo dd if=$IDBLOADER of=$1 conv=fsync bs=512 seek=64
#sudo dd if=$IDBLOADER of=$1 bs=512 seek=0 count=2048 conv=fsync,notrunc
sudo dd if=$IDBLOADER of=$1 bs=512 seek=0 count=16384 conv=fsync
#sudo dd if=$UBOOT of=$1 bs=512 seek=0 count=24575 conv=fsync
sudo dd if=$UBOOT of=$1 conv=fsync bs=512 seek=16384
#sudo dd if=$TRUST of=$1 conv=fsync bs=512 seek=24576

sync

sudo eject $1

echo Finished





#UBOOT=./rk3566_tool/uboot.img
#if [ -z $1 ]; then
#        echo "Usage ./sd_fusing.sh <SD card reader's device>"
#        exit 1
#fi
#sudo dd if=$UBOOT of=$1 bs=512 seek=0 count=24575 conv=fsync
#sync
#sudo eject $1
#echo Finished
