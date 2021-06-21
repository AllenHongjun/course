sudo apt-get install git build-essential gdb-multiarch qemu-system-misc gcc-riscv32-linux-gnu binutils-riscv32-linux-gnu


/root/riscv-gnu-toolchain

./configure --prefix=/root/riscv-gnu-toolchain --with-arch=rv32gc --with-abi=ilp32d

./configure --prefix=/root/riscv-gnu-toolchain --enable-multilib

./configure --disable-kvm --disable-werror --prefix=/root/riscv-gnu-toolchain --target-list="riscv64-softmmu"


-- 方法总比困难多呀。。
https://blog.csdn.net/kingroc/article/details/86526150
https://blog.csdn.net/kingroc/article/details/86526150


git config --global --unset url.https://github.com/riscv.insteadOf git://github.com/riscv

git config --global --unset url.https://anongit.freedesktop.org/git/.insteadOf git://anongit.freedesktop.org/
