#!/bin/sh

if [ -n "$DESTDIR" ] ; then
    case $DESTDIR in
        /*) # ok
            ;;
        *)
            /bin/echo "DESTDIR argument must be absolute... "
            /bin/echo "otherwise python's distutils will bork things."
            exit 1
    esac
    DESTDIR_ARG="--root=$DESTDIR"
fi

echo_and_run() { echo "+ $@" ; "$@" ; }

echo_and_run cd "/home/mensonli/FusionAD/src/utility/ethz_piksi_ros/rqt_gps_rtk_plugin"

# ensure that Python install destination exists
echo_and_run mkdir -p "$DESTDIR/home/mensonli/FusionAD/install/lib/python2.7/dist-packages"

# Note that PYTHONPATH is pulled from the environment to support installing
# into one location when some dependencies were installed in another
# location, #123.
echo_and_run /usr/bin/env \
    PYTHONPATH="/home/mensonli/FusionAD/install/lib/python2.7/dist-packages:/home/mensonli/FusionAD/build/lib/python2.7/dist-packages:$PYTHONPATH" \
    CATKIN_BINARY_DIR="/home/mensonli/FusionAD/build" \
    "/usr/bin/python" \
    "/home/mensonli/FusionAD/src/utility/ethz_piksi_ros/rqt_gps_rtk_plugin/setup.py" \
    build --build-base "/home/mensonli/FusionAD/build/utility/ethz_piksi_ros/rqt_gps_rtk_plugin" \
    install \
    $DESTDIR_ARG \
    --install-layout=deb --prefix="/home/mensonli/FusionAD/install" --install-scripts="/home/mensonli/FusionAD/install/bin"
