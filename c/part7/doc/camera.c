#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <linux/videodev2.h>


#define WIDTH 1280
#define HEIGHT 720

int main(int argc, char* argv[]){
	
	int tmp, i=0;
	const char* device = "/dev/video0";
	
	int camera_fd = open(device, O_RDWR);
	if(camera_fd==-1){
		perror("camera");
		return -1;
	}
	
	struct v4l2_fmtdesc fmt_get;
	struct v4l2_format fmt_set;
	memset(&fmt_get, 0, sizeof(fmt_get));
	
	//设置摄像头参数
	fmt_get.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
	fmt_set.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
	fmt_set.fmt.pix.width = WIDTH;
    fmt_set.fmt.pix.height = HEIGHT;
    fmt_set.fmt.pix.pixelformat = V4L2_PIX_FMT_MJPEG;
    fmt_set.fmt.pix.sizeimage = WIDTH * HEIGHT;


	while (1)
    {
        fmt_get.index = i++;
        tmp = ioctl(camera_fd,VIDIOC_ENUM_FMT,&fmt_get);
        if(tmp < 0)
            break;
 
        printf("index=%d\n", fmt_get.index);
        printf("description=%s\n", fmt_get.description);
        unsigned char *p = (unsigned char *)&fmt_get.pixelformat;
        printf("pixelformat=%c%c%c%c\n", p[0],p[1],p[2],p[3]);
    }
 
	close(camera_fd);
	
    return 0;
}


