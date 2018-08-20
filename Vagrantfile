
Vagrant.configure("2") do |config|
  config.vm.box = "ubuntu/bionic64"

  config.vm.provision "shell", inline: <<-SHELL
    curl -sL https://deb.nodesource.com/setup_10.x | bash -
    apt-get update
    apt-get -y dist-upgrade
    apt-get -y install linux-modules-extra-$(uname -r) v4l-utils build-essential nodejs
    npm i -g yarn
    adduser vagrant video
    # reboot

    # for v4l-utils:
    # apt-get install -y debhelper dh-autoreconf autotools-dev autoconf-archive \
    #   doxygen graphviz libasound2-dev libtool libjpeg-dev libqt4-dev \
    #   libqt4-opengl-dev libudev-dev libx11-dev pkg-config udev make gcc git
  SHELL
end
