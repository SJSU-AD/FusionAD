%% Preliminary Setup

% Author: Menson Li  
% File Name: transform_test.m  
% Brief: Transformation proof for SJSU FusionAD project.  
% Date: 12/26/2018

% Clear out workspace
clc, clear, close all

%%
%{
p = [1;-1;0];

theta = deg2rad(45);

rot_mat_zz = [cos(theta) -sin(theta) 0; sin(theta) cos(theta) 0; 0 0 1];

p_adj = rot_mat_zz*p;

p_vec_x = [0 p(1)];
p_vec_y = [0 p(2)];
p_adj_vec_x = [0 p_adj(1)];
p_adj_vec_y = [0 p_adj(2)];

figure();
plot(p_vec_x,p_vec_y,'x-');
hold on;
plot(p_adj_vec_x,p_adj_vec_y,'o-');
grid on;
legend('Pre-transform', 'After transform');
%}

% Check Transformation matrix

%{
wp = [1 1 0 1]';
To_wp = eye(4);
To_wp(1:4,4) = wp; 

theta = deg2rad(45);

car = [1 0.5 0 1]';
To_car = [cos(theta) -sin(theta) 0 1;
          sin(theta) cos(theta) 0 1;
          0 0 1 0;
          0 0 0 1];
To_car(1:4,4) = car;
car_dx = [car(1) car(1)+0.5*cosd(45)];
car_dy = [car(2) car(2)+0.5*sind(45)];

Tcar_wp = inv(To_car)*To_wp;

figure();
plot(wp(1),wp(2),'x');
hold on;
plot(car_dx,car_dy,'o-');
grid on;
plot(Tcar_wp(1,4),Tcar_wp(2,4), '*');
legend('OG_waypoint', 'CAR', 'After TF WP');

car_wp_dx = car(1)-wp(1);
car_wp_dy = car(2)-wp(2);

disp(['Distance to origin after TF: ' sqrt(Tcar_wp(1,4)^2+Tcar_wp(2,4)^2)]);
disp(['Relative distance before tf to car: ' sqrt(car_wp_dx^2+car_wp_dy^2)]);
%}

% Proof check relative angle
%{
wp = [1 1 0 1]';
To_wp = eye(4);
To_wp(1:4,4) = wp; 

theta = deg2rad(45);

car = [1 0.5 0 1]';
To_car = [cos(theta) -sin(theta) 0 1;
          sin(theta) cos(theta) 0 1;
          0 0 1 0;
          0 0 0 1];
To_car(1:4,4) = car;
car_dx = [car(1) car(1)+0.5*cosd(45)];
car_dy = [car(2) car(2)+0.5*sind(45)];

Tcar_wp = inv(To_car)*To_wp;

wp_car_dx = wp(1)-car(1);
wp_car_dy = wp(2)-car(2);

relative_theta = atan2(wp_car_dy,wp_car_dx) - theta;
relative_theta_tf = atan2(Tcar_wp(2,4),Tcar_wp(1,4));

disp(['Relative theta before TF:' num2str(relative_theta)]);
disp(['Relative theta after TF:' num2str(relative_theta_tf)]);

% This proves that the relative angle between the position vector of the
% waypoint relative to the car's coordinate frame is the same as the
% position vector of the waypoint relative to the global origin frame after
% transform.
%}

% Check if the waypoint is ahead (in the positive X axis region of the car
% fixed frame).

%% Final Proof
% Input: Waypoint position ("wp" array [x y z 1]')
%        Vehicle orientation ("theta")
%        Vehicle position ("car" array [x y z 1]')
clear, clc, close all;
wp = [1 3 0 1]';
To_wp = eye(4);
To_wp(1:4,4) = wp; 

% Theta is the orientation of the vehicle
theta = deg2rad(-32);

car = [1 0.5 0 1]';
To_car = [cos(theta) -sin(theta) 0 1;
          sin(theta) cos(theta) 0 1;
          0 0 1 0;
          0 0 0 1];
To_car(1:4,4) = car;
car_dx = 0.5*cos(theta);
car_dy = 0.5*sin(theta);

Tcar_wp = inv(To_car)*To_wp;

wp_car_dx = wp(1)-car(1);
wp_car_dy = wp(2)-car(2);

if(Tcar_wp(1,4) > 0)
    disp(['Waypoint is ahead (x) by: ' Tcar_wp(1,4) 'meter']);
else
    disp(['Waypoint is trailing (x) by: ' Tcar_wp(1,4) 'meter']);
end

% Checks
% The two distance values must equal for the transform to be valid.
% The two angle values must equal for the tranform to be valid.
disp(['Distance to origin after TF: ' num2str(sqrt(Tcar_wp(1,4)^2+Tcar_wp(2,4)^2))]);
disp(['Relative distance before tf to car: ' num2str(sqrt(wp_car_dx^2+wp_car_dy^2))]);

relative_theta = atan2(wp_car_dy,wp_car_dx) - theta;
relative_theta_tf = atan2(Tcar_wp(2,4),Tcar_wp(1,4));

disp(['Relative theta before TF: ' num2str(relative_theta)]);
disp(['Relative theta after TF: ' num2str(relative_theta_tf)]);
% End of checks

figure();
plot(wp(1),wp(2),'x', 'MarkerSize', 10);
hold on;
%plot(car_dx,car_dy,'o-');
quiver(car(1),car(2),car_dx,car_dy,0);
grid on;
plot(Tcar_wp(1,4),Tcar_wp(2,4), '^','MarkerSize', 10);
quiver(0,0,0.5,0,0);

legend('OG_waypoint', 'CAR', 'After TF WayPoint', 'Car fixed frame Origin');
xlim([-3 3]);
ylim([-3 3]);


%% Extracts TF equations
clear all;
syms wp_x wp_y car_x car_y theta

% This equation assumes planar space, not 3D space. Thus, z components of
% the two position vectors are 0.

%wp = [wp_x; wp_y; 0; 1];
%To_wp = eye(4);
%To_wp(1:4,4) = wp; 

To_wp = [1 0 0 wp_x;
         0 1 0 wp_y;
         0 0 1 0;
         0 0 0 1];

% Theta is the orientation of the vehicle
%theta = deg2rad(45);

%car = [car_x; car_y; 0; 1];
To_car = [cos(theta) -sin(theta) 0 car_x;
          sin(theta) cos(theta) 0 car_y;
          0 0 1 0;
          0 0 0 1];
To_car_R = To_car(1:3,1:3);
trans_To_car_R = [cos(theta) sin(theta) 0;
                  -sin(theta) cos(theta) 0;
                  0 0 1;];
              
inv_coordinate = (-1)*trans_To_car_R*To_car(1:3,4);
      
inv_To_car = [ trans_To_car_R inv_coordinate;
               0 0 0 1];
      
Tcar_wp = inv_To_car*To_wp;
disp('Homogeneous Transformation Maxtrix of the Waypoint frame wrt Vehicle body fixed frame:');
Tcar_wp;
disp('The X component of the transformed waypoint is:');
Tcar_wp(1,4)

%% Proof the generated equation is correct;
clear all;
wp = [1 1 0 1]';
To_wp = eye(4);
To_wp(1:4,4) = wp; 

% Theta is the orientation of the vehicle
theta = deg2rad(-90);

car = [1 0.5 0 1]';
To_car = [cos(theta) -sin(theta) 0 1;
          sin(theta) cos(theta) 0 1;
          0 0 1 0;
          0 0 0 1];
To_car(1:4,4) = car;
car_dx = 0.5*cos(theta);
car_dy = 0.5*sin(theta);

Tcar_wp = inv(To_car)*To_wp;

car_x = car(1);
car_y = car(2);
wp_x = wp(1);
wp_y = wp(2);

x_gen_eqn = wp_x*cos(theta) - car_y*sin(theta) - car_x*cos(theta) + wp_y*sin(theta);
x_ans = Tcar_wp(1,4);

absolute_answer_difference = abs(x_ans - x_gen_eqn);

% Check if the answer tolerance is within 1 %
% The tolerance won't work if the waypoint is exactly lined up with the
% location of the car at the x axis (x=0), because x*0.01 = 0.

if(absolute_answer_difference < (x_ans*0.01))
    disp('Equation is proved');
    fprintf('Equation Outputs: %f\n', x_gen_eqn);
    fprintf('Mathematical Solution: %f\n',x_ans);
else
    disp('Equation is wrong');
    format long;
    disp('Equation answer:');
    x_gen_eqn
    disp('Model Answer:');
    x_ans    
end