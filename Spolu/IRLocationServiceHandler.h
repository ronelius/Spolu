//
//  IRLocationServiceHandler.h
//  Spolu
//
//  Created by Marcus Ronélius on 2015-02-21.
//  Copyright (c) 2015 Spolu Apps. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

@protocol LocationServiceHandlerDelegate;

@interface IRLocationServiceHandler : NSObject <CLLocationManagerDelegate>
{
    
}

@property (nonatomic, strong) id<LocationServiceHandlerDelegate>delegate;

@property (nonatomic, strong) CLLocationManager *locationManager;

@property (nonatomic) float currentLocationCoordinateY;
@property (nonatomic) float currentLocationCoordinateX;
@property (nonatomic, strong) NSString *currenctLocationCity;

//  LocationServiceHandlerDelegate Error Codes:
//  -1  = Not allowed to use location. Global
//  0   = Not allowed to use location. Implicit disallowed for this app
//  1   = Location data was not found. Probably temporary...
//  2   = Unknown location data error
    @property (nonatomic, strong) NSError *locationError;


+ (IRLocationServiceHandler *)sharedLocationServiceHandler;
- (instancetype)init;

- (void)startUpdatingLocation;
- (void)stopUpdatingLocation;
- (void)sendCurrentErrorToDelegate;

@end;

@protocol LocationServiceHandlerDelegate <NSObject>
@optional

- (void)locationServiceHandler:(IRLocationServiceHandler *)service didUpdateCurrentLocation:(NSString *)city
                      latitude:(float)latitude
                     longitude:(float)longitude;

- (void)locationServiceHandler:(IRLocationServiceHandler *)service didFailGettingLocation:(NSError *)error;

@end