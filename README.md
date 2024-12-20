# pxtoneGM

**Supported platforms:** Windows, Windows (YYC)\
**Supported versions:** GM8.1, GM:S, GMS2.x,
x86 runtimes on GM2022 (pre-[GM2022.8](https://gamemaker.io/en/blog/release-2022-8))

This is a wrapper for [pxtone](https://pxtone.org/)'s
Windows DLL!
It lets you play music made in pxtone Collage.

It's intended to be API-compatible with the [2010 DLL](https://web.archive.org/web/20191125085328/http://gmc.yoyogames.com/index.php?showtopic=470034) by Anokorok.

## Differences

- Does not depend on an antique version of Microsoft Visual C++ Runtime Redistributable
- GM:S/newer extensions use the extension system to load the extension instead of calling `pxtone_init_wrapper()` yourself.
- Buffer functions for GM:S and newer
- Added a few other missing functions.
- There's `pxtone_get_clock` instead of `pxtone_get_sample` because no copies of the DLL with that addition have survived and I can't tell what it's supposed to return (or even what the `clock` callback returns, really).

## Caveats

So I have implemented the library from [this official website](https://studiopixel.sakura.ne.jp/pxtone/), which 

1. Doesn't have a 64-bit version
2. Doesn't support some of the tracks made with latest Collab..?  
  Even though that version string appears in the DLL

But instead I should have been implementing the library from [_this_ official website](https://pxtone.org/developer/), which is cross-platform and has a completely different API.

Here's my reaction to finding that out after I already wrote most of the code and started testing the thing on various tracks:  
![](export/yalDissatisfied.png)



## Meta
Consider this to be MIT or whatever.