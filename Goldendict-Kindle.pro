TEMPLATE = subdirs

SUBDIRS = deps/coolreader/cr3-kindle/src/device \
    deps/goldendict \
    deps/libgd \
    app

arm {
    SUBDIRS += deps/coolreader/drivers/QKindleFb \
    deps/coolreader/drivers/KindleTS \
    deps/coolreader/drivers/KindleKeyboard
}

CONFIG += ordered
