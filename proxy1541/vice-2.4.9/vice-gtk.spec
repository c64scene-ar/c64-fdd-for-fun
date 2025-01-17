Name:		vice
Version:	2.4.9
Release:	1%{?dist}
Summary:	Versatile Commodore 8-bit Emulator
Vendor:		VICE Team
Group:		Applications/Emulators
License:	GPLv2
URL:		http://vice-emu.sourceforge.net/
Source0:	http://www.zimmers.net/anonftp/pub/cbm/crossplatform/emulators/VICE/%{name}-%{version}.tar.gz
BuildRoot:	%{_tmppath}/%{name}-%{version}-%{release}-root-%(%{__id_u} -n)
Packager:	VICE Team
BuildRequires:	alsa-lib-devel ffmpeg-devel gettext-devel giflib-devel gtk2-devel gtkglext-devel lame-devel libieee1284-devel libjpeg-devel libpcap-devel libpng-devel libX11-devel libXrandr-devel mesa-libGL-devel pulseaudio-libs-devel zlib-devel
# Requires:	ffmpeg-libs lame-libs


%description
This is version 2.4.9 of VICE, the multi-platform C64, C128, VIC20,
PET, PLUS4, CBM-II and C64DTV emulator.


%prep
%setup -q


%build
%define __global_cflags -O3 -ffast-math -g -pipe -Wall -fexceptions -Wp,-D_FORTIFY_SOURCE=2 -fstack-protector --param=ssp-buffer-size=4
%if 0%{?archopt:1}
  %define optflags %{__global_cflags} %{archopt}
%else
  %if %{_target_cpu} == i686
    %define optflags %{__global_cflags} -m32 -march=pentium-m -fasynchronous-unwind-tables
  %else
    %if %{_target_cpu} == x86_64
      %define optflags %{__global_cflags} -m64 -march=nocona -mtune=core2
    %endif
  %endif
%endif
%configure --docdir=%{_docdir}/%{name}-%{version}/doc --enable-gnomeui --enable-ethernet --enable-parsid --without-oss --disable-arch
make %{?_smp_mflags}


%install
rm -rf %{buildroot}
# Generated Makefile ignores docdir from configure
make install DESTDIR=%{buildroot} realdocdir=%{_docdir}/%{name}-%{version}/doc
rm -f %{buildroot}%{_infodir}/dir
%{__install} -D -p -m 0644 AUTHORS ChangeLog FEEDBACK COPYING INSTALL NEWS README %{buildroot}%{_docdir}/%{name}-%{version}
%find_lang vice


%clean
rm -rf %{buildroot}


%post
/sbin/install-info %{_infodir}/vice.info.gz %{_infodir}/dir


%preun
if [ "$1" = 0 ]; then
 /sbin/install-info --delete %{_infodir}/vice.info.gz %{_infodir}/dir
fi


%files -f vice.lang
%defattr(-,root,root,-)
%{_docdir}/%{name}-%{version}/*
%{_bindir}/*
%{_prefix}/lib/vice/*
%{_infodir}/vice.info.gz
%{_infodir}/vice.txt.gz
%{_mandir}/man1/* 
%{_datadir}/locale/*/LC_MESSAGES/vice.mo


%changelog
* Fri Feb 25 2011 Dag Lem <resid@nimrod.no> - 2.3-1
- Update of requirements and configuration.
- Added missing files, fix for 64 bit builds.
- Less conservative architecture specific optimizations:
    rpmbuild --define "archopt <archopt>"    -> gcc -O3 <archopt>
    rpmbuild [--target=i686-<vendor>-<os>]   -> gcc -O3 -march=pentium-m
    rpmbuild [--target=x86_64-<vendor>-<os>] -> gcc -O3 -march=prescott -mtune=core2

* Tue Oct 28 2008 Ingvar Hagelund <ingvar@linpro.no> - 2.0-1
- Wrap up a new package
