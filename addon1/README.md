Node.js Hello World Addon
=========================

The current documentation on making a 'Hello World' addon on [Node.js](https://nodejs.org/api/addons.html#addons_hello_world)'s guide is outdated. This repo is an example on how to make a simple Hello World addon.

This example comes with `binding.gyp`, `hello.cc`, and `hello.js`, as well as a pre-built `hello.node` module.

### Running

To run this example, make sure you are in this folder in your terminal, and type:

```
node hello.js
```

### Compiling

To make changes / add to / compile this addon, node-gyp is required.
First, install node-gyp:

```
npm install -g node-gyp
```

Then, configure and build your changes:

```
node-gyp configure
node-gyp build
```

